// <stdlib.h>
#define ppřiděl(x) malloc(x) // paměť přiděl
#define čpřiděl(x, y) calloc(x, y) // čistou paměť přiděl
#define osvoboď(x) free(x)

#define řnač(x) atoi(x) // řetězec na číslo
#define řdoč(x) atoi(x)
#define řnap(x) atof(x) // řetězec na plav
#define řdop(x) atof(x)
#define řnad(x) atol(x) // řetězec na dlouhý
#define řdod(x) atol(x)
#define řnadd(x) atoll(x) // řetězec na dlouhý dlouhý
#define řdodd(x) atoll(x)

#define řeťnad(x, y, z) strtol(x, y, z) // řetězec na dlouhý
#define řeťdod(x, y, z) strtol(x, y, z)
#define řeťnadd(x, y, z) strtoll(x, y, z) // řetězec na dlouhý dlouhý
#define řeťdodd(x, y, z) strtoll(x, y, z)

#define řeťnand(x, y, z) strtoul(x, y, z) // řetězec na neznaménkový dlouhý
#define řeťdond(x, y, z) strtoul(x, y, z)
#define řeťnandd(x, y, z) strtoull(x, y, z) // řetězec na neznaménkový dlouhý dlouhý
#define řeťdondd(x, y, z) strtoull(x, y, z)

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

