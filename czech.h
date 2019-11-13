// typy
#define SOUBOR FILE
#define plav float
#define číslo int
#define znak char
#define dlouhé long
#define dlouhý long
#define krátké short
#define krátký short
#define znaménkové sign
#define znaménkový sign
#define neznaménkové unsign
#define neznaménkový unsign

//logické konstrukce
#define když if
#define jestli if
#define jinak else
#define dokud while
#define pro for
#define dělej do
#define přepínač switch
#define případ case

//konstanty
#define pravda 1
#define nepravda 0
#define lež 0
#define KŘ '\n'
#define KS -1 //Konec Souboru
#define NULA ((char *)0)

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
#define sčtif(...) fscanf(__VA_ARGS__)
#define tisknif(...) printf(__VA_ARGS__)
#define čtif(...) scanf(__VA_ARGS__)

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

