#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../czech.h"

číslo hlavní(prázdno) začni
  snáho(čas(NULA)) vole

  číslo inp vole
  tisknif("Zadej náhodné číslo, 1-10: ") vole
  sčtif(standovnitř, "%d", &inp) vole

  pokud(inp je_menší 1 nebo inp je_větší 10) začni
    stisknif(stanchyb, "Číslo %d není v rozsahu 1-10!\n", inp) vole
    vrať 1 vole
  skonči

  tisknif("\n") vole

  číslo rannum rovná_se náho() % 10 + 1 vole

  pokud(inp rovný rannum) začni
    tisknif("Gratuluji! Uhodl jsi číslo %d!\n", rannum) vole
  skonči jinak začni
    tisknif("Škoda, vymyslel jsem si číslo %d, ne %d.\n", rannum, inp) vole
  skonči

skonči
