# Č

The Czech library for C. Why? Because we could, of course!

Please contribute your other ~~horrible~~ awesome and creative translations
so that we can write a fully czech code to suit all our needs.

## Using

This project resides solely in a single header file, aptly named `czech.h`.
Download that file alone, or the entire repository, and then, after
including it in your source files like you would any other header, you'll
be good to go! (Just make sure to use a relatively modern compiler)

This project has been tested with and works for
[Clang](http://releases.llvm.org/download.html), but newer versions of gcc
are also known to work, as well as some other compilers.

## Integrated transpiler
For testing, we also provide C to Č and a reverse transpiler in the file
`translate.py`. Launch it with `./translate.py to czech.h path/to/your/C/file.c path/to/new/Č/file.č`

## Obligatory "Hello World" example

```c
#include "czech.h"
#include <stdio.h>

číslo hlavní(prázdno)
{
    položř("Ahoj, světe!");
    vrať 0;
}
```
