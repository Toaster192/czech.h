/*
   ▀█▄▄█▀
    ▄▄▄▄
  ██▀▀▀▀█
 ██▀
 ██
 ██▄
  ██▄▄▄▄█
    ▀▀▀▀
*/
// typy
#define SOUBOR FILE
#define plav float
#define plov float
#define plovoucí float
#define vznášej float
#define dvojnásobný double
#define dvojnásobná double
#define dvojnásobné double
#define dvojitý double
#define dvojitá double
#define dvojité double
#define číslo int
#define cel int // INTeger -> CELé číslo
#define znak char
#define dlouhý long
#define dlouhá long
#define dlouhé long
#define krátký short
#define krátká short
#define krátké short
#define znaménkový signed
#define znaménková signed
#define znaménkové signed
#define bezznaménkový unsigned
#define bezznaménková unsigned
#define bezznaménkové unsigned
#define neznaménkový unsigned
#define neznaménková unsigned
#define neznaménkové unsigned
#define prázdno void
#define prázdný void
#define prázdná void
#define prázdné void
#define nijaký void
#define nijaká void
#define nijaké void
#define prázdnota void
#define pravdivost bool

// pokročilé celočíselné typy
#define velikost_t size_t
#define číslo8_t int8_t
#define číslo16_t int16_t
#define číslo32_t int32_t
#define číslo64_t int64_t
#define nčíslo8_t uint8_t
#define nčíslo16_t uint16_t
#define nčíslo32_t uint32_t
#define nčíslo64_t uint64_t
#define cel8_t int8_t
#define cel16_t int16_t
#define cel32_t int32_t
#define cel64_t int64_t
#define ncel8_t uint8_t
#define ncel16_t uint16_t
#define ncel32_t uint32_t
#define ncel64_t uint64_t

// logické konstrukce
#define když if
#define pokud if
#define jestli if
#define jestliže if
#define jinak else
#define dokud while
#define zatímco while
#define pro for
#define dělej do
#define udělej do
#define proveď do
#define přepínač switch
#define případ case
#define výchozí default
#define rozbij break
#define rozbít break
#define přeruš break
#define přerušit break
#define pokračuj continue

// ostatní klíčová slova
#define vrať return
#define navrať return
#define stálý static
#define stálá static
#define stálé static
#define konst const
#define konstantní const
#define neměnný const
#define neměnná const
#define neměnné const
#define jdido goto
#define velikost(x) sizeof(x)

#define hlavní main

// operátory
#define je ==
#define rovný ==
#define rovná ==
#define rovné ==
#define rovno ==
#define rovnáse ==
#define není !=
#define nerovný !=
#define nerovná !=
#define nerovné !=
#define nerovno !=
#define nerovnáse !=

// experimentální triky
#define začátek {
#define začni {
#define konec }
#define skonči }

#define major *
#define podplukovník **
#define plukovník ***
#define brigádní_generál *
#define generálmajor **
#define generálporučík ***
#define armádní_generál ****

// režimy otevření souboru
#define ČTENÍ "r"
#define ZÁPIS "w"
#define PŘÍPIS "a"
#define DVOJKOVÉ_ČTENÍ "rb"
#define DVOJKOVÝ_ZÁPIS "wb"
#define DVOJKOVÝ_PŘÍPIS "wa"

// standardní I/O streamy
#define standovnitř stdin
#define stanvstup stdin
#define stando stdin
#define stanvýstup stdout
#define stanven stdout
#define stanchyb stderr

#define stídovnitř stdin
#define stívstup stdin
#define stído stdin
#define stívýstup stdout
#define stíven stdout
#define stíchyb stderr

// konstanty
#define pravda 1
#define vcajku 1
#define blbě 0
#define nepravda 0
#define lež 0
#define KŘ '\n'
#define KS -1 //Konec Souboru
#define NULA NULL

// Knihovny

// <stdio.h>
#include "spnvv.h"

// <stdlib.h>
#include "spnkni.h"

// <string.h>
#include "retezec.h"

// <float.h>
#include "plav.h"

// <math.h>
#include "matika.h"

/*
   ▀█▄▄█▀
    ▄▄▄▄       ▄█▀                 ▄█▀                 ▄█▀
  ██▀▀▀▀█     ▀▀                  ▀▀                  ▀▀
 ██▀        ▄████▄   ██▄███▄    ▄████▄   ██▄███▄    ▄████▄
 ██        ██▄▄▄▄██  ██▀  ▀██  ██▄▄▄▄██  ██▀  ▀██  ██▄▄▄▄██
 ██▄       ██▀▀▀▀▀▀  ██    ██  ██▀▀▀▀▀▀  ██    ██  ██▀▀▀▀▀▀
  ██▄▄▄▄█  ▀██▄▄▄▄█  ███▄▄██▀  ▀██▄▄▄▄█  ███▄▄██▀  ▀██▄▄▄▄█
    ▀▀▀▀     ▀▀▀▀▀   ██ ▀▀▀      ▀▀▀▀▀   ██ ▀▀▀      ▀▀▀▀▀
                     ██                  ██
*/
// c -> character -> znak -> z
#define zven cout
#define zvýstup cout
#define zdovnitř cin
#define zvstup cin
#define zdo cin
#define zerr cerr
#define zchyb cerr

#define cven cout
#define cvýstup cout
#define cdovnitř cin
#define cvstup cin
#define cdo cin
#define cchyb cerr

#define používá using
#define jménovesmír namespace
#define jmennýprostor namespace
// std -> sexually transmitted disease -> Sexuálně přenosná nemoc -> spn
#define spn std
#define stí std

#define vektor vector
#define zatlač_zpátky push_back
#define zatlač_zpět push_back
#define zatlač_dozadu push_back
#define strč_zpátky push_back
#define strč_zpět push_back
#define strč_dozadu push_back
