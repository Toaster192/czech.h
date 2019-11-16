#!/usr/bin/python3
import sys
import re
import os

PLACEHOLDER_PATTERNS = [r'"(?:[^\\"]|\\.)*"', r"'\\?.'",
                        r'//[^\r\n]*', r'/\*[\s\S]*?\*/']
NUMBER_REGEX = re.compile(r'-?\d+(?:\.\d+)?', re.UNICODE)
DEFINE_REGEX = re.compile(
    r'^\s*#define\s+(\w+)(?:\([^\)\n]*\))?\s+([^\(\)\n]+?)(?:\([^\)\n]*\))?\s*(?://.*)?$', re.UNICODE | re.MULTILINE)

FLAG_TO = 'to'
FLAG_FROM = 'from'

if __name__ == '__main__':
    # Parse command-line arguments.

    if len(sys.argv) != 5:
        print('Syntax: <direction> <czech.h path> <input C file path> <output Č file path>')
        exit(1)

    direction = sys.argv[1]
    def_file = sys.argv[2]
    input_file = sys.argv[3]
    output_file = sys.argv[4]

    if direction not in [FLAG_TO, FLAG_FROM]:
        print('Valid directions:')
        print('  to   -- From English to Czech')
        print('  from -- From Czech to English')
        exit(1)

    try:
        with open(def_file, 'r', encoding='utf8') as f:
            definitions = f.read()
    except Exception as ex:
        print('Cannot read header file:', ex)
        exit(1)

    try:
        with open(input_file, 'r', encoding='utf8') as f:
            code = f.read()
    except Exception as ex:
        print('Cannot read source file:', ex)
        exit(1)

    # Replace strings, characters and comments with placeholders.

    placeholders = dict()
    for pattern in PLACEHOLDER_PATTERNS:
        for p in re.finditer(pattern, code, re.UNICODE | re.MULTILINE):
            value = p[0]

            if value in placeholders.values():
                continue

            placeholder = f'_PLACEHOLDER_{len(placeholders)}_'
            placeholders[placeholder] = value

            code = code.replace(value, placeholder)

    # Apply definitions.

    for d in DEFINE_REGEX.finditer(definitions):
        source, target = (d[1], d[2]) if direction == FLAG_FROM \
            else (d[2], d[1])

        if not re.fullmatch(r'^\w+$', source, re.UNICODE) or re.fullmatch(r'^\d+$', source, re.UNICODE):
            continue

        code = re.sub(f'\\b{source}\\b', target, code, flags=re.UNICODE)

    # Put placeholders back in their respective places.

    for k, v in placeholders.items():
        code = code.replace(k, v)

    include_path = os.path.relpath(
        os.path.abspath(def_file),
        start=os.path.dirname(os.path.abspath(output_file))).replace('\\', '/')

    # Add/remove `#include` directive.

    INCLUDE = "#include"
    def_file_include = f'{INCLUDE} "{include_path}"\n'

    if direction == FLAG_TO:
        if INCLUDE in code:
            code = code.replace(INCLUDE, def_file_include + INCLUDE, 1)
        else:
            code = defFileInclude + code

    else:
        code = code.replace(def_file_include, '')

    # Write output to the output file.

    with open(output_file, 'w', encoding='utf8', newline='\n') as f:
        f.write(code)
