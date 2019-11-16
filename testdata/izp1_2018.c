/**
 * @file izp1_2018.c
 * @author Ivo Meixner (xmeixn00@stud.fit.vutbr.cz)
 * @brief First VUT FIT IZP project
 * @version 1.0
 * @date 2018-10-15
 *
 * @copyright Copyright (c) 2018
 *
 * **Extra commands**
 *  - Find (`fPATTERN`)
 *  - Conditional Goto (`cX PATTERN`)
 *  - Append EOL (`e`)
 *
 * **Extra features**
 *  - Infinite loop detection
 *
 * **Notes**
 *  - The expression `strlen(X) - 1` is often used as an index throughout the project.
 *    It always refers to the last character of the string `X`.
 *  - Strings are considered to be too long when `strlen(X) >= LINE_LEN_MAX` is true
 *    because `strlen()` does not count the terminating null character into the length of the string.
 *  - The Append / After (`a`) command is implemented to support an arbitrary number of newline characters
 *    at the end of the current line. Hence the `countTrailingLFs()` function.
 *  - The expression `&string[1]` is used occasionally to get a substring beginning at the second character.
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Maximum number of lines / commands in the command file.
 *
 */
#define CMD_LINES_MAX 100

/**
 * @brief Maximum character per line in both the command file and the input text file.
 *
 */
#define LINE_LEN_MAX 1001

/**
 * @brief Error message which is printed when executing the command would cause a buffer overflow.
 *
 */
static const char* const ERR_STR_TOO_LONG = "Result string would be too long for the current line buffer\n";

/**
 * @brief Value returned when the pattern string is not found in the main string.
 *
 */
static const int STR_NOT_FOUND = -1;

/**
 * @brief Numeric base to be used by strtol() calls.
 *
 */
static const int STRTOL_BASE = 10;

/**
 * @brief Exit code used when everything goes right.
 *
 */
static const int EXIT_CODE_OK = 0;

/**
 * @brief Exit code used when something goes wrong.
 *        It is universally used for all errors that can occur.
 *
 */
static const int EXIT_CODE_GENERIC_ERROR = -1;

/**
 * @brief Attempts to parse an unsigned integer value from a string.
 *
 * This is just a strtol() function wrapper for a more efficient use in this project.
 *
 * @param[in] str Input string to parse the integer value from.
 * @param[out] output Pointer to the output integer variable.
 * @return true if an integer has been successfully parsed.
 * @return false if the function was unable to parse an integer value.
 */
bool parseInt(const char* const str, int* const output)
{
    char* end = NULL;
    *output = strtol(str, &end, STRTOL_BASE);
    return end != NULL && *end == '\0';
}

/**
 * @brief Removes line feed character ('\\n') from the end of a string.
 *
 * The line feed character will be replaced with the null character ('\\0').
 * Boolean value indicating if the string really had
 * a line feed character at its end will be returned.
 *
 * @param[in,out] str String to remove the line feed character from.
 * @return true if the string ended with a line feed character.
 * @return false if the string had no line feed at the end.
 */
bool removeLF(char* const str)
{
    const int len = strlen(str);
    const bool endsWithEOL = len > 0 && str[len - 1] == '\n';

    if (endsWithEOL)
    {
        str[len - 1] = '\0';
    }

    return endsWithEOL;
}

/**
 * @brief Reads all the lines / commands from the command file into a 2D array.
 *
 * @param[in] cmdFilePath Path of the command file.
 * @param[out] cmdArray Output 2D array to store the commands in.
 * @param[out] cmdCount Pointer to integer variable, in which the number of read commands will be stored.
 * @return true if the commands have been read successfully.
 * @return false if the attempt to read the command file has failed.
 */
bool readCmdFile(const char* const cmdFilePath, char cmdArray[][LINE_LEN_MAX], int* const cmdCount)
{
    FILE* const cmdFile = fopen(cmdFilePath, "r");

    if (cmdFile == NULL)
    {
        fprintf(stderr, "Unable to read command file: \"%s\"\n", cmdFilePath);
        return false;
    }

    // Read all the lines from the command file and count them.
    int count = 0;
    for (count = 0; count < CMD_LINES_MAX; count++)
    {
        char* const cmd = cmdArray[count];

        if (fgets(cmd, LINE_LEN_MAX, cmdFile) == cmd)
        {
            // Remove the newline character from each command.
            removeLF(cmd);
        }
        else
        {
            break;
        }
    }

    // Copy the number of commands loaded to the output variable.
    (*cmdCount) = count;

    fclose(cmdFile);
    return true;
}

/**
 * @brief Reads the next line from STDIN.
 *
 * @param[out] line String to store the read line in.
 * @return true if a line has been successfully read.
 * @return false if the end-of-file has been hit, indicating there is nothing more to read.
 */
bool getNextLine(char* const line)
{
    // If the fgets() function returns anything else than the first pointer passed to it,
    // the end-of-file has been reached and there is nothing more to be read.
    return fgets(line, LINE_LEN_MAX, stdin) == line;
}

/**
 * @brief Prints the current line STDOUT and moves on to the next line.
 *
 * @param[in,out] line String in which the current line is stored and the new line will be put into.
 * @param[out] missingNewline Idicates if the trailing newline was missing from the printed line.
 * @return true if there is another line.
 * @return false if there are no more lines.
 */
bool flushLine(char* const line, bool* const missingNewline)
{
    int len = printf("%s", line);
    *missingNewline = line[len - 1] != '\n';
    return getNextLine(line);
}

/**
 * @brief Counts the number of line feed characters at the end of the string.
 *
 * @param[in] str Input string.
 * @param[in] len Length of the input string.
 * @return int Number of line feed characters at the end of the string.
 */
int countTrailingLFs(const char* const str, const int len)
{
    int count = 0;

    for (int i = len - 1; i >= 0 && str[i] == '\n'; i--)
    {
        count++;
    }

    return count;
}

/**
 * @brief Finds a substring within a string and returns its index. Length of the main string and the substring must be supplied.
 *
 * @param[in] str String to look for the substring in. Also referred to as the main string.
 * @param[in] len Length of the main string.
 * @param[in] pattern Substring to look for.
 * @param[in] patternLen Length of the substring.
 * @return int Index of the substring within the main string or -1 if the substring is not contained in the main string.
 */
int strFindWithLengths(const char* const str, const int len, const char* const pattern, const int patternLen)
{
    // The main string must be at least as long as the pattern string
    // and both of them must be at least 1 character long.
    if (len <= 0 || patternLen <= 0 || patternLen > len)
    {
        return STR_NOT_FOUND;
    }

    // Iterate through the main string until the pattern is found.
    // The length of the pattern is subtracted because it would not fit any farther in the main string.
    for (int i = 0; i < len - patternLen + 1; i++)
    {
        bool match = true;

        // Compare the pattern with substrings from the main string character by character.
        for (int j = 0; j < patternLen; j++)
        {
            if (str[i + j] != pattern[j])
            {
                match = false;
                break;
            }
        }

        // If a match is found, return the index at which it begins.
        if (match)
        {
            return i;
        }
    }

    return STR_NOT_FOUND;
}

/**
 * @brief Finds a substring within a string and returns its index.
 *
 * @param[in] str String to look for the substring in. Also referred to as the main string.
 * @param[in] pattern Substring to look for.
 * @return int Index of the substring within the main string or -1 if the substring is not contained in the main string.
 */
int strFind(const char* const str, const char* const pattern)
{
    return strFindWithLengths(str, strlen(str), pattern, strlen(pattern));
}

/**
 * @brief Shifts part of a string (substring) starting at a given index by a specified number of characters.
 *
 * @param[in,out] str String to work with.
 * @param[in] oldLen Length of the string before the shift.
 * @param[in] start Start index of substring to shift.
 * @param[in] shift Number of characters to shift the substring by. Positive for shifting to the right; negative for shifting to the left.
 */
void shiftSubstring(char* const str, const int oldLen, const int start, const int shift)
{
    if (shift == 0)
    {
        return;
    }

    // Calculate the new length.
    const int newLen = oldLen + shift;

    // Shift right (forward).
    if (shift > 0)
    {
        for (int i = oldLen - 1; i >= start; i--)
        {
            str[i + shift] = str[i];
        }
    }
    // Shift left (backwards).
    else if (shift < 0)
    {
        for (int i = start; i < oldLen; i++)
        {
            str[i + shift] = str[i];
        }
    }

    // Insert the terminating null character.
    str[newLen] = '\0';
}

/**
 * @brief Internal function used for the actual string replacement once the pattern index is already known.
 *
 * @param[in,out] str String to perform the replacement on.
 * @param[in] oldLen Length of the string before the replacement.
 * @param[in] patternIndex Index at which the pattern was found. The substitution will begin at this index.
 * @param[in] patternLen Length of the pattern string to be replaced. This number of character will be removed from the string.
 * @param[in] replacement String to replace the pattern with.
 * @param[in] replacementLen Length of the replacement string.
 */
void strReplaceInner(char* const str, const int oldLen,
                     const int patternIndex, const int patternLen,
                     const char* const replacement, const int replacementLen)
{
    // Shift the right part (after pattern) by the difference between
    // pattern a replacement string lengths.
    const int shift = replacementLen - patternLen;
    shiftSubstring(str, oldLen, patternIndex + patternLen, shift);

    // Copy the replacement string over the pattern.
    for (int i = 0; i < replacementLen; i++)
    {
        str[patternIndex + i] = replacement[i];
    }
}

/**
 * @brief Replaces the first occurrence of a pattern within a string with a replacement string.
 *
 * @param[in,out] str String to perform the replacement on.
 * @param[in] pattern Pattern substring to look for.
 * @param[in] patternLen Length of the pattern.
 * @param[in] replacement String to replace the pattern with.
 * @param[in] replacementLen Length of the replacement string.
 * @return true if the function finished successfully.
 * @return false if the result string would be too long.
 */
bool strReplaceFirst(char* const str, const char* const pattern, const int patternLen,
                     const char* const replacement, const int replacementLen)
{
    const int oldLen = strlen(str);
    const int patternIndex = strFindWithLengths(str, oldLen, pattern, patternLen);

    if (patternIndex != STR_NOT_FOUND)
    {
        // Check the length of the result string to make sure it will not be too long.
        if (oldLen - patternLen + replacementLen >= LINE_LEN_MAX)
        {
            fprintf(stderr, ERR_STR_TOO_LONG);
            return false;
        }
        else
        {
            strReplaceInner(str, oldLen, patternIndex, patternLen, replacement, replacementLen);
        }
    }

    return true;
}

/**
 * @brief Replaces all occurrences of a pattern within a string with a replacement string.
 *
 * @param[in,out] str String to perform the replacement on.
 * @param[in] pattern Pattern substring to look for.
 * @param[in] patternLen Length of the pattern.
 * @param[in] replacement String to replace the pattern with.
 * @param[in] replacementLen Length of the replacement string.
 * @return true if the function finished successfully.
 * @return false if the result string would be too long.
 */
bool strReplaceAll(char* const str, const char* const pattern, const int patternLen,
                   const char* const replacement, const int replacementLen)
{
    int startIndex = 0;
    int relativePatternIndex = 0;

    // Continue while the pattern is contained in the yet-untouched part of the string.
    while ((relativePatternIndex = strFind(&str[startIndex], pattern)) != STR_NOT_FOUND)
    {
        const int oldLen = strlen(str);

        // Check the length of the result string to make sure it will not be too long.
        if (oldLen - patternLen + replacementLen >= LINE_LEN_MAX)
        {
            fprintf(stderr, ERR_STR_TOO_LONG);
            return false;
        }

        const int absolutePatternIndex = startIndex + relativePatternIndex;
        strReplaceInner(str, oldLen, absolutePatternIndex, patternLen, replacement, replacementLen);

        // Put the search start index at the end of the last replacement string.
        startIndex = absolutePatternIndex + replacementLen;
    }

    return true;
}

/**
 * @brief Parses the pattern from the substitution command arguments.
 *
 * @param[in] cmdArgs Arguments supplied to the substitution command.
 * @param[in] cmdArgsLen Length of the supplied arguments.
 * @param[out] pattern Pointer to the character array used to store the pattern.
 * @param[out] patternLenPtr Poitner to the integer variable used to store the length of the pattern.
 * @return true if the pattern was successfully parsed.
 * @return false if the function was unable to parse the pattern.
 */
bool parseSubstitutionPattern(const char* const cmdArgs, const int cmdArgsLen,
                              char* const pattern, int* const patternLenPtr)
{
    // Get the separator character.
    const char separator = cmdArgs[0];
    int patternLen = 0;

    // Skip the first character, because that is the separator.
    for (int i = 1; i < cmdArgsLen; i++)
    {
        char c = cmdArgs[i];

        // Stop iterating once the second separator is reached.
        if (c == separator)
        {
            pattern[patternLen] = '\0';
            break;
        }
        else
        {
            pattern[patternLen++] = c;
        }
    }

    (*patternLenPtr) = patternLen;

    // The pattern must be at least 1 character long and there must be
    // 2 separator characters in the substitute commnad arguments.
    return patternLen > 0 && patternLen <= cmdArgsLen - 2;
}

/**
 * @brief Parses the substitution command arguments into their respective variables and arrays.
 *
 * @param[in] cmdArgs Arguments supplied to the substitution command.
 * @param[out] pattern Pointer to the character array used to store the pattern.
 * @param[out] patternLenPtr Poitner to the integer variable used to store the length of the pattern.
 * @param[out] replacement Pointer to the character array used to store the replacement string.
 * @param[out] replacementLenPtr Poitner to the integer variable used to store the length of the replacement string.
 * @return true if the substitution command arguments were parsed successfully.
 * @return false if the function was not able to parse the command arguments.
 */
bool parseSubstitutionArgs(const char* const cmdArgs, char* const pattern, int* const patternLenPtr,
                           char* const replacement, int* const replacementLenPtr)
{
    const int cmdArgsLen = strlen(cmdArgs);

    // There must be 2 separator characters and at least 1 pattern character in the command arguments.
    if (cmdArgsLen < 3 || !parseSubstitutionPattern(cmdArgs, cmdArgsLen, pattern, patternLenPtr))
    {
        return false;
    }

    int replacementLen = 0;

    for (int i = (*patternLenPtr) + 2; i < cmdArgsLen; i++)
    {
        replacement[replacementLen++] = cmdArgs[i];
    }

    replacement[replacementLen] = '\0';
    (*replacementLenPtr) = replacementLen;

    return true;
}

/**
 * @brief Throws an error if a command which expects no arguments has been supplied an argument.
 *
 * @param[in] cmdArgs Arguments supplied to the command. Should be an empty string if everything is OK.
 * @param[in] cmdName Full name of the command.
 * @param[in] cmdPrefix Prefix character of the command.
 * @return true if the command arguments are empty (as expected).
 * @return false if there are any (unexpected) command arguments.
 */
bool checkNoArgs(const char* const cmdArgs, const char* const cmdName, const char cmdPrefix)
{
    bool noArgs = cmdArgs[0] == '\0';

    if (!noArgs)
    {
        fprintf(stderr, "Unexpected %s command arguments: \"%s\"\nCommand %s (%c) expects no arguments.\n", cmdName, cmdArgs, cmdName, cmdPrefix);
    }

    return noArgs;
}

/**
 * @brief Checks validity of the new command index and sets it if the index is valid.
 *
 * @param[in] cmdCount Number of commands in the command array.
 * @param[in] newIndex 1-based index of the next command to execute.
 * @param[in,out] cmdIndex Pointer to the command index.
 * @return true if the command index is valid.
 * @return false if the command index is not valid.
 */
bool changeCmdIndexIfValid(const int cmdCount, const int newIndex, int* const cmdIndex)
{
    const int zeroBasedIndex = newIndex - 1;
    const bool validIndex = zeroBasedIndex >= 0 && zeroBasedIndex < cmdCount;

    if (validIndex)
    {
        // Command index is incremented at the end of each iteration,
        // so it needs to be decremented first to account for that.
        (*cmdIndex) = zeroBasedIndex - 1;
    }
    else
    {
        fprintf(stderr, "Command index %d is too high; the command file has only %d line(s)\n", newIndex, cmdCount);
    }

    return validIndex;
}

/**
 * @brief Handles the INSERT command by printing the specified content.
 *
 * @param[in] cmdArgs Content supplied to the command, which will be printed before the current line.
 */
void cmdInsert(const char* const cmdArgs)
{
    printf("%s\n", cmdArgs);
}

/**
 * @brief Handles the BEFORE command by prepending the specified content to the beginng of the current line.
 *
 * @param[in] cmdArgs Content supplied to the command to be put before the current line.
 * @param[in,out] line String containing the current line.
 * @return true if the function finished successfully.
 * @return false if something went wrong (e.g., the total number of character exceeded the maximum length).
 */
bool cmdBefore(const char* const cmdArgs, char* const line)
{
    const int beforeLen = strlen(cmdArgs);
    const int lineLen = strlen(line);
    const int lenSum = beforeLen + lineLen;

    if (lenSum >= LINE_LEN_MAX)
    {
        fprintf(stderr, ERR_STR_TOO_LONG);
        return false;
    }

    if (beforeLen == 0)
    {
        return true;
    }

    // Shift the old string by the length of CONTENT to the right (forward).
    shiftSubstring(line, lineLen, 0, beforeLen);

    // Copy the CONTENT to the beginning of the current line.
    for (int i = 0; i < beforeLen; i++)
    {
        line[i] = cmdArgs[i];
    }

    line[lenSum] = '\0';
    return true;
}

/**
 * @brief Handles the APPEND / AFTER command by appending the specified content to the end of the current line.
 *
 * @param[in] cmdArgs Content supplied to the command to be put at the end of the current line.
 * @param[in,out] line String containing the current line.
 * @return true if the function finished successfully.
 * @return false if something went wrong (e.g., the total number of character exceeded the maximum length).
 */
bool cmdAppend(const char* const cmdArgs, char* const line)
{
    const int appendLen = strlen(cmdArgs);
    const int lineLen = strlen(line);
    const int lenSum = lineLen + appendLen;

    if (lenSum >= LINE_LEN_MAX)
    {
        fprintf(stderr, ERR_STR_TOO_LONG);
        return false;
    }

    // Count the number of newline characters at the end of the current line.
    const int lineLFCount = countTrailingLFs(line, lineLen);

    if (appendLen == 0)
    {
        return true;
    }

    // Copy the CONTENT to the end of the current line, but before any trailing newline character(s).
    for (int i = 0; i < appendLen; i++)
    {
        line[lineLen - lineLFCount + i] = cmdArgs[i];
    }

    // Put the right number of newline characters at the end of the current line.
    for (int i = 0; i < lineLFCount; i++)
    {
        line[lenSum - lineLFCount + i] = '\n';
    }

    line[lenSum] = '\0';
    return true;
}

/**
 * @brief Deletes the current line or the specified number of lines based on supplied arguments.
 *
 * @param[in] cmdArgs Command arguments. Can be either empty (delete current line) or a positive integer (delete N lines).
 * @param[in,out] line String containing the current line.
 * @return true if there are more lines to work with.
 * @return false if the end of the text file has been reached or the arguments are invalid.
 */
bool cmdDeleteLine(const char* const cmdArgs, char* const line)
{
    int count = 1;

    if (cmdArgs[0] != '\0' && !parseInt(cmdArgs, &count))
    {
        fprintf(stderr, "Unexpected delete line command arguments: \"%s\"\n", cmdArgs);
        return false;
    }

    for (int j = 0; j < count; j++)
    {
        if (!getNextLine(line))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Handles the REMOVE EOL command by removing the line feed character from the end of the current line.
 *
 * @param[in] cmdArgs Arguments provided to the command. This command always expects no arguments, so any arguments will cause an error.
 * @param[in,out] line String containing the current line.
 * @return true if there were no arguments and command has been executed successfully.
 * @return false if the command has failed to execute, most likely due to unexpected arguments.
 */
bool cmdRemoveEOL(const char* const cmdArgs, char* const line)
{
    bool noArgs = checkNoArgs(cmdArgs, "remove EOL", 'r');

    if (noArgs)
    {
        removeLF(line);
    }

    return noArgs;
}

/**
 * @brief Handles the logic of all substitution commands.
 *
 * @param[in] cmdArgs Arguments supplied to the substitution argument. All substitution commands take arguments in the same format.
 * @param[in,out] line String containing the current line.
 * @param[in] replaceAll Specifies whether all occurrences of the pattern string should be replaced or only the first one.
 * @return true if the function finished successfully.
 * @return false if something went wrong (e.g., the result string would be too long).
 */
bool cmdSubstitute(const char* const cmdArgs, char* const line, const bool replaceAll)
{
    char pattern[LINE_LEN_MAX];
    int patternLen = 0;

    char replacement[LINE_LEN_MAX];
    int replacementLen = 0;

    if (!parseSubstitutionArgs(cmdArgs, pattern, &patternLen, replacement, &replacementLen))
    {
        fprintf(stderr, "Unexpected substitution command arguments: \"%s\"\n", cmdArgs);
        return false;
    }

    if (replaceAll)
    {
        return strReplaceAll(line, pattern, patternLen, replacement, replacementLen);
    }
    else
    {
        return strReplaceFirst(line, pattern, patternLen, replacement, replacementLen);
    }
}

/**
 * @brief Handles the NEXT LINE command by printing the current line and moving on to the next line of text.
 *
 * @param[in] cmdArgs Command arguments specifying how many lines should the program move.
 * @param[in,out] line String containing the current line.
 * @param[out] missingNewline Pointer to a boolean value indicating if the last printed line was missing a newline at its end.
 * @return true if there are more lines to work with.
 * @return false if the end of the text file has been reached or the arguments are invalid.
 */
bool cmdNextLine(const char* const cmdArgs, char* const line, bool* const missingNewline)
{
    int count = 1;

    if (cmdArgs[0] != '\0' && !parseInt(cmdArgs, &count))
    {
        fprintf(stderr, "Unexpected next line command arguments: \"%s\"\n", cmdArgs);
        return false;
    }

    for (int i = 0; i < count; i++)
    {
        if (!flushLine(line, missingNewline))
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Handles the QUIT command by making sure there were no unexpected arguments and optionally prints the final newline.
 *
 * @param[in] cmdArgs Command arguments, which should always be empty for this command.
 * @param[in] missingNewline Boolean value specifying if the newline character was missing from the last printed line.
 * @return true if the command execution was successful.
 * @return false if the command exectuion failed, most likely due to unexpected arguments.
 */
bool cmdQuit(const char* const cmdArgs, const bool missingNewline)
{
    bool noArgs = checkNoArgs(cmdArgs, "quit", 'q');

    if (noArgs && missingNewline)
    {
        printf("\n");
    }

    return noArgs;
}

/**
 * @brief Handles the GOTO command by changing the command index.
 *
 * @param[in] cmdArgs Command arguments containg the line number of the next command to execute.
 * @param[in] cmdCount Number of commands in the command array.
 * @param[out] cmdIndex Pointer to the command index.
 * @return true if the function finished successfully.
 * @return false if something went wrong.
 */
bool cmdGoto(const char* const cmdArgs, const int cmdCount, int* const cmdIndex)
{
    int gotoIndex = 0;

    if (parseInt(cmdArgs, &gotoIndex))
    {
        return changeCmdIndexIfValid(cmdCount, gotoIndex, cmdIndex);
    }
    else
    {
        fprintf(stderr, "Unexpected goto command arguments: \"%s\"\n", cmdArgs);
        return false;
    }
}

/**
 * @brief Handles the FIND command by finding a line containing the pattern supplied in command arguments.
 *
 * @param[in] cmdArgs Command arguments containing the pattern to look for.
 * @param[in,out] line String containing current line.
 * @return true if line containing the pattern was found.
 * @return false if no such line was found and the command ran to the end of the file.
 */
bool cmdFind(const char* const cmdArgs, char* const line)
{
    do
    {
        if (strFind(line, cmdArgs) != STR_NOT_FOUND)
        {
            return true;
        }

        printf("%s", line);
    } while (getNextLine(line));

    return false;
}

/**
 * @brief Handles the CONDITIONAL GOTO command by jumping to the specified command if the current line contains the supplied pattern.
 *
 * @param[in] cmdArgs Command arguments containing the command index and the pattern to look for.
 * @param[in] cmdCount Number of commands in the command array.
 * @param[in] line String containing the current line.
 * @param[out] cmdIndex Pointer to the command index variable.
 * @return true if the function finished successfully.
 * @return false if something went wrong.
 */
bool cmdConditionalGoto(const char* const cmdArgs, const int cmdCount,
                        const char* const line, int* const cmdIndex)
{
    char* end = NULL;
    const int gotoIndex = strtol(cmdArgs, &end, STRTOL_BASE);

    // There must be a space and a pattern string after the command file line number.
    if (end == NULL || end[0] != ' ' || end[1] == '\0')
    {
        fprintf(stderr, "Unexpected conditional goto command arguments: \"%s\"\n", cmdArgs);
        return false;
    }

    if (strFind(line, &end[1]) != STR_NOT_FOUND)
    {
        return changeCmdIndexIfValid(cmdCount, gotoIndex, cmdIndex);
    }

    return true;
}

/**
 * @brief Appends a line feed character to the end of the current line.
 *
 * @param[in] cmdArgs Arguments provided to the command. This command always expects no arguments, so any arguments will cause an error.
 * @param[in,out] line String containing the current line.
 * @return true if there were no arguments and command has been executed successfully.
 * @return false if the command has failed to execute (unexpected arguments, result string is too long).
 */
bool cmdAppendEOL(const char* const cmdArgs, char* const line)
{
    // Check there are no arguments.
    if (!checkNoArgs(cmdArgs, "append EOL", 'e'))
    {
        return false;
    }

    // Calculate the new current line length.
    const int newLen = strlen(line) + 1;

    // The new length must be at least 1 character lower than the maximum length,
    // otherwise the terminating null character will not fit in the string.
    if (newLen >= LINE_LEN_MAX)
    {
        fprintf(stderr, ERR_STR_TOO_LONG);
        return false;
    }
    else
    {
        // Add the line feed character to the end of the string and terminate it with the null character.
        line[newLen - 1] = '\n';
        line[newLen] = '\0';

        return true;
    }
}

/**
 * @brief Performs finishing actions once the main runtime loop is finished.
 *
 * @param[in,out] line String containing the current line.
 * @param[in] keepGoing Boolean value indicating whether the program should continue running.
 * @param[in,out] missingNewline Pointer to a boolean value indicating if the last printed line was missing a newline at its end.
 */
void finish(char* const line, const bool keepGoing, bool* const missingNewline)
{
    // Flush the remaining input text lines to STDOUT if the main loop was supposed to continue iterating.
    if (keepGoing)
    {
        while (flushLine(line, missingNewline))
            ;
    }

    // Add the final newline character if the last printed line did not end with one.
    if (*missingNewline)
    {
        printf("\n");
    }
}

/**
 * @brief Updates the indicator of modifications on the current line.
 *
 * @param cmdPrefix Prefix of the command to evaluate.
 * @param modified Indicator of current line modifications.
 */
void updateLineModified(const char cmdPrefix, bool* modified)
{
    switch (cmdPrefix)
    {
    // Commands that modify the current line.
    case 'b':
    case 'a':
    case 'r':
    case 's':
    case 'S':
    case 'e':
        *modified = true;
        break;

    // Commands that load the next line and reset modification indicator.
    case 'd':
    case 'n':
    case 'f':
        *modified = false;
        break;

    // Other commands that do not directly affect the current line.
    default:
        break;
    }
}

/**
 * @brief Main runtime loop, in which the command are iterated through and exected.
 *
 * @param[in] cmdArray 2D array of commands.
 * @param[in] cmdCount Number of commands.
 * @return true if the commands have been executed successfully.
 * @return false if the command execution failed.
 */
bool run(char cmdArray[][LINE_LEN_MAX], const int cmdCount)
{
    char line[LINE_LEN_MAX];            // Current line string.
    bool keepGoing = getNextLine(line); // Should loop keep iterating?
    bool missingNewline = false;        // Was the last printed line missing EOL?
    bool modified = false;              // Has the current line been modified?

    // Iterate through commands while there are commands and input text lines available.
    for (int i = 0; i < cmdCount && keepGoing; i++)
    {
        const char cmdPrefix = cmdArray[i][0];       // Command prefix character.
        const char* const cmdArgs = &cmdArray[i][1]; // Command arguments.

        switch (cmdPrefix)
        {
        case 'i':
            cmdInsert(cmdArgs);
            break;

        case 'b':
            keepGoing &= cmdBefore(cmdArgs, line);
            break;

        case 'a':
            keepGoing &= cmdAppend(cmdArgs, line);
            break;

        case 'd':
            keepGoing &= cmdDeleteLine(cmdArgs, line);
            break;

        case 'r':
            keepGoing &= cmdRemoveEOL(cmdArgs, line);
            break;

        case 's':
            keepGoing &= cmdSubstitute(cmdArgs, line, false);
            break;

        case 'S':
            keepGoing &= cmdSubstitute(cmdArgs, line, true);
            break;

        case 'n':
            keepGoing &= cmdNextLine(cmdArgs, line, &missingNewline);
            break;

        case 'q':
            if (modified)
                flushLine(line, &missingNewline);
            return cmdQuit(cmdArgs, missingNewline);

        case 'g':
            keepGoing &= cmdGoto(cmdArgs, cmdCount, &i);
            break;

        case 'f':
            keepGoing &= cmdFind(cmdArgs, line);
            break;

        case 'c':
            keepGoing &= cmdConditionalGoto(cmdArgs, cmdCount, line, &i);
            break;

        case 'e':
            keepGoing &= cmdAppendEOL(cmdArgs, line);
            break;

        default:
            fprintf(stderr, "Unexpected command prefix: '%c' (%x)\n", cmdPrefix, cmdPrefix);
            keepGoing = false;
            break;
        }

        updateLineModified(cmdPrefix, &modified);
    }

    // Finish by printing the remaining input text lines and the final newline.
    finish(line, keepGoing, &missingNewline);

    // The function has finished successfully if the end-of-file has been reached.
    return feof(stdin);
}

/**
 * @brief Prints brief information about the program; most importatntly its usage syntax.
 *
 */
void printHelp(void)
{
    fprintf(stderr, "%s\n\n%s\n%s\n\n%s\n%s\n%s\n\n",
            "ed-like single-line CLI text editor",
            "Usage:",
            "    ./proj1 <command file path>",
            "Notes:",
            "    Input text is supplied using STDIN.",
            "    Commands are read one-per-line from a command file.");
}

/**
 * @brief Find out if the command array contains any GOTO command that would cause and infinite loop.
 *
 * If a GOTO command is hit twice without a new line being loaded, there is an infinite loop.
 * If a new line has been loaded between the two hits,
 * the loop will keep running until it runs out of input text lines.
 * This means that no other commands outside of the GOTO's range will ever be hit,
 * meaning it is unnecessary to check them for another infinite loop.
 * This logic is not exactly perfectly compatible with the Conditional GOTO command
 * because it behaves relative unpredictable and detecting an infinite loop in a command file
 * involving the Conditional GOTO command would be quite frankly slightly too complicated.
 *
 * @param[in] cmdArray 2D array containing all the commands.
 * @param[in] cmdCount Number of commands in the command array.
 * @return int 1-based index of line containing the GOTO causing the infinite loop or 0 if no infinite loop was found.
 */
int findInfiniteLoop(char cmdArray[][LINE_LEN_MAX], const int cmdCount)
{
    // Indicates if a GOTO command has been hit once already.
    bool gotoHit[CMD_LINES_MAX] = {false};
    // Indicates if a new line has been loaded since the last time a command has been hit.
    bool lineSince[CMD_LINES_MAX] = {false};

    // Iterate through the commands.
    for (int i = 0; i >= 0 && i < cmdCount; i++)
    {
        switch (cmdArray[i][0])
        {
        case 'n':
        case 'd':
            // A line has been loaded since any and all commands.
            memset(lineSince, true, sizeof(bool) * CMD_LINES_MAX);
            break;

        case 'g':
            // This GOTO command has already been hit for the second time.
            if (gotoHit[i])
            {
                // If there was no line loaded, there is an infinite loop, otherwise there is not.
                return lineSince[i] ? 0 : i + 1;
            }

            // Reset new line loaded indicator and mark the GOTO command as hit for the first time.
            lineSince[i] = false;
            gotoHit[i] = true;

            // Prase the GOTO command arguments (if any) and perform it.
            if (!parseInt(&cmdArray[i][1], &i))
            {
                return 0;
            }

            // Check the GOTO command handler function for detailed explanation.
            i -= 2;
            break;

        case 'q':
            return 0;

        default:
            break;
        }
    }

    return 0;
}

/**
 * @brief Program entry point.
 *
 * @param[in] argc Number of CLI arguments.
 * @param[in] argv Array containing the CLI arguments.
 * @return int Exit code.
 */
int main(const int argc, const char* const* const argv)
{
    // Check the number of CLI arguments.
    if (argc != 2)
    {
        printHelp();
        return EXIT_CODE_OK;
    }

    char cmdArray[CMD_LINES_MAX][LINE_LEN_MAX]; // 2D command array.
    int cmdCount = 0;                           // Number of commands.

    // Load the commands from the command file.
    if (!readCmdFile(argv[1], cmdArray, &cmdCount))
    {
        return EXIT_CODE_GENERIC_ERROR;
    }

    const int infLoopLine = findInfiniteLoop(cmdArray, cmdCount);

    if (infLoopLine)
    {
        fprintf(stderr, "Infinite loop detected, caused by goto at line %d\n", infLoopLine);
        return EXIT_CODE_GENERIC_ERROR;
    }

    return run(cmdArray, cmdCount) ? EXIT_CODE_OK : EXIT_CODE_GENERIC_ERROR;
}
