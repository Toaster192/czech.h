# Č

The czech library to C because we could

Please contribute with other horrible translations so we can make a full czech
sample code later

## Using

Clone the repository or download the `czech.h` file and include it in your C
code just like you would include any other header file.

So far we have only been able to compile the code using
[Clang](http://releases.llvm.org/download.html) or [tcc](https://bellard.org/tcc/).

If you manage to compile it using GCC, please let us know how.

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
