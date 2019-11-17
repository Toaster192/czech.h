#include "../czech.h"
#include <stdio.h>

číslo hlavní(prázdno) {
    číslo čísloTyp;
    plav plavTyp;
    dvojitý dvojitýTyp;
    znak znakTyp;
    // Velikost operator is used to evaluate the size of a variable
    tisknif("Size of číslo: %ld bytes\n", velikost(čísloTyp));
    tisknif("Size of plav: %ld bytes\n", velikost(plavTyp));
    tisknif("Size of dvojitý: %ld bytes\n", velikost(dvojitýTyp));
    tisknif("Size of znak: %ld byte\n", velikost(znakTyp));
    vrať 0;
}
