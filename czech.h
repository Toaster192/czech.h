// typy
#define SOUBOR FILE
#define plav float
#define dvojnásobný double
#define číslo int
#define znak char
#define dlouhé long
#define dlouhý long
#define krátké short
#define krátký short
#define znaménkové signed
#define znaménkový signed
#define neznaménkové unsigned
#define neznaménkový unsigned
#define prázdno void
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

// logické konstrukce
#define když if
#define jestli if
#define jinak else
#define dokud while
#define pro for
#define dělej do
#define přepínač switch
#define případ case
#define výchozí default
#define rozbij break
#define pokračuj continue

// ostatní klíčová slova
#define vrať return
#define stálé static
#define stálý static
#define neměnné const
#define neměnný const
#define jdido goto

#define hlavní main

// operátory
#define je ==
#define není !=

// experimentální triky
#define začátek {
#define začni {
#define konec }
#define skonči }

// režimy otevření souboru
#define ČTENÍ "r"
#define ZÁPIS "w"
#define PŘÍPIS "a"
#define DVOJKOVÉ_ČTENÍ "rb"
#define DVOJKOVÝ_ZÁPIS "wb"
#define DVOJKOVÝ_PŘÍPIS "wa"

// standardní I/O streamy
#define stanvstup stdin
#define stanvýstup stdout
#define stanchyb stderr

// konstanty
#define pravda 1
#define nepravda 0
#define lež 0
#define KŘ '\n'
#define KS -1 //Konec Souboru
#define NULA NULL

// <stdio.h>
#define smaž(x) remove(x)
#define přejmenuj(x, y) rename(x, y)
#define dočsoubor() tmpfile()
#define dočjmén(x) tmpnam(x)
#define szavři(x) fclose(x)
#define sspláchni(x) fflush(x)
#define sotevři(x, y) fopen(x, y)
#define sznovuotevři(x, y, z) freopen(x, y, z)
#define nastavmísto(x, y) setbuf(x, y)
#define přenastavmísto(x, y, z, a) setvbuf(x, y, z, a)
#define stisknif(...) fprintf(__VA_ARGS__)
#define sčtif(...) fscanf(__VA_ARGS__)
#define tisknif(...) printf(__VA_ARGS__)
#define čtif(...) scanf(__VA_ARGS__)

// <stdlib.h>
#define ppřiděl(x) malloc(x) // paměť přiděl
#define čpřiděl(x, y) calloc(x, y) // čistou paměť přiděl
#define osvoboď(x) free(x)

#define řnač(x) atoi(x) // řetězec na číslo
#define řnap(x) atof(x) // řetězec na plav
#define řnad(x) atol(x) // řetězec na dlouhý
#define řnadd(x) atoll(x) // řetězec na dlouhý dlouhý

#define náho() rand()

// místo délka tisk formát
#define mdtisknif(...) snprintf(__VA_ARGS__)
#define mtisknif(...) sprintf(__VA_ARGS__)
#define mčtif(...) sscanf(__VA_ARGS__)
// proměnný souborový tisk formátovaný
#define pstisknif(...) vfprintf(__VA_ARGS__)
#define psčtif(...) vfscanf(__VA_ARGS__)
#define ptisknif(...) vprintf(__VA_ARGS__)
#define pčtif(...) vscanf(__VA_ARGS__)
#define pmdtisknif(...) vsnprintf(__VA_ARGS__)
#define pmtisknif(...) vsprintf(__VA_ARGS__)
#define pmčtif(...) vsscanf(__VA_ARGS__)
#define sdostaňz(x) fgetc(x)
#define sdostaňř(x, y, z) fgets(x, y, z)
#define spoložz(x, y) fputc(x, y)
#define spoložř(x, y) fputs(x, y)
#define dostaňz(x) getc(x)
#define dostaňznak(x) getchar(x)
#define dostaňř(x) gets(x)
#define položz(x, y) putc(x, y)
#define položznak(x) putchar(x)
#define položř(x) puts(x)
#define oddostaňz(x, y) ungetc(x, y)
#define spřečti(x, y, z, a) fread(x, y, z, a)
#define szapiš(x, y, z, a) fwrite(x, y, z, a)
#define sdostaňpoz(x, y) fgetpos(x, y)
#define snajdi(x, y, z) fseek(x, y, z)
#define snastavpoz(x, y) fsetpos(x, y)
#define sřekni(x) ftell(x)
#define přetoč(x) rewind(x)
#define vyčistichyb(x) clearerr(x)
#define sks(x) feof(x)
#define schyba(x) ferror(x)
#define tchybu(x) perror(x)
