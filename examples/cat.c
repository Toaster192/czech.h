#include "../czech.h"
#include <stdio.h>

číslo hlavní(neměnné číslo počet, neměnný znak* neměnný* neměnný hodnoty)
{
    jestli (počet není 2)
    {
        spoložř("Očekávána jedna hodnota - cesta vstupního souboru", stanchyb);
        vrať 1;
    }

    SOUBOR* neměnný s = sotevři(hodnoty[1], ČTENÍ);

    jestli (s je NULA)
    {
        spoložř("Nelze otevřít vstupní soubor", stanchyb);
        vrať 2;
    }

    pro (číslo z; (z = sdostaňz(s)) není KS;)
    {
        položz(z, stanvýstup);
    }

    szavři(s);
    vrať 0;
}
