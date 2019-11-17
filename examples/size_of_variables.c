#include "../czech.h"
#include <stdio.h>

číslo hlavní(prázdno) {
    číslo čísloTyp;
    plav plavTyp;
    dvojitý dvojitýTyp;
    znak znakTyp;
    // Operátor rozměr se používá ke zjištění velikosti typu
    tisknif("Velikost čísla je: %ld bajtů\n", rozmer(čísloTyp));
    tisknif("Velikost plavání je: %ld bajtů\n", rozmer(plavTyp));
    tisknif("Velikost dvojitého je: %ld bajtů\n", rozmer(dvojitýTyp));
    tisknif("Velikost znaku je: %ld bajt\n", rozmer(znakTyp));
    vrať 0;
}
