
#ifndef CZECH_H_
#define CZECH_H_
// typy
#define SOUBOR FILE

#define rozhodovák bool
#define plav float
#define plovák float
#define tuplák double
#define číslo int
#define čís int
#define znak char
#define dlouhé long
#define dlouhý long
#define dlouhán long
#define hafodlouhán long long
#define krátké short
#define krátký short
#define kraťas short
#define znaménkové signed
#define znaménkový signed
#define podepsaný signed
#define nepodepsaný unsigned
#define neznaménkové unsigned
#define neznaménkový unsigned
#define prázdno void
#define prázdnota void


// logické konstrukce
#define běžna goto
#define když if
#define jestli if
#define jinak else
#define takne else
#define dokud while
#define pro for
#define dělej do
#define přepínač switch
#define případ case
#define výchozí default
#define pokračovat continue
#define prolomit break

//práce s typy
#define rozměr sizeof
#define novytyp typedef

#define skladba struct
#define výčet enum
#define CCCP union

// ostatní klíčová slova
#define vrať return
#define stálý static
#define nehybný static
#define neměnný const
#define brusle inline
#define měňavec volatile
#define autobus auto
#define venkovní extern

// konstanty
#define pravda 1
#define nabeton true
#define nepravda false
#define lež 0
#define KŘ '\n'
#define KS -1 //Konec Souboru
#define NIC NULL
#define NULA NULL

#define stdven stdout
#define stdchyb stderr
#define stddovnitř stdin

//funkce
#define hlavní(...) main(__VA_ARGS__)  

// stdio
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
#define spiš(...)   fprintf(__VA_ARGS__)
#define sčtif(...) fscanf(__VA_ARGS__)
#define tisknif(...) printf(__VA_ARGS__)
#define piš(...)    printf(__VA_ARGS__)
#define čtif(...) scanf(__VA_ARGS__)

//stdlib
#define navalp(...)	malloc(__VA_ARGS__) //naval paměť
#define čnavalp(...) calloc(__VA_ARGS__)  //naval čistou paměť
#define znavalp(...) realloc(__VA_ARGS__) //znovu naval paměť
#define zdarmap(...) free(__VA_ARGS__)  //free memory (paměť zdarma)
#define potrat(...)	abort(__VA_ARGS__)
#define přiútěku(...) atexit(__VA_ARGS__)
#define rozděl(...)	div(__VA_ARGS__)
#define vemroha(...) exit(__VA_ARGS__)
#define náhoda(...)	rand(__VA_ARGS__)
#define pravácesta(...)	realpath(__VA_ARGS__)
#define snáhoda(...) srand(__VA_ARGS__)
#define řetnatu(...) strtod(__VA_ARGS__)
#define řetnapl(...) strtof(__VA_ARGS__)
#define řetnadl(...) strtol(__VA_ARGS__)
#define řetnadtu(...) strtold(__VA_ARGS__)
#define řetnahdl(...) strtoll(__VA_ARGS__)
#define řetnandl(...) strtoul(__VA_ARGS__)
#define řetnanhdl(...) strtoull(__VA_ARGS__)

//stdint.h
#define nčís8_t uint8_t
#define pčís8_t int8_t
#define nčís16_t uint16_t
#define pčís16_t int16_t
#define nčís32_t uint32_t
#define pčís32_t int32_t
#define nčís64_t uint64_t
#define pčís64_t int64_t

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

#endif
