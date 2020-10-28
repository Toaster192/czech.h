// typy
#define SOUBOR FILE
#define plav float
#define plovoucí float
#define vznášej float
#define dvojnásobný double
#define dvojitý double
#define dvojité double
#define číslo int
#define znak char
#define dlouhé long
#define dlouhý long
#define krátké short
#define krátký short
#define znaménkové signed
#define znaménkový signed
#define bezznaménkový unsigned
#define bezznaménkové unsigned
#define neznaménkové unsigned
#define neznaménkový unsigned
#define prázdno void
#define prázdný void
#define prázdná void
#define prázdné void
#define nijaký void
#define nijaké void
#define nijaká void
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
#define pokud if
#define jestli if
#define jestliže if
#define jinak else
#define dokud while
#define zatímco while
#define pro for
#define dělej do
#define přepínač switch
#define případ case
#define výchozí default
#define rozbij break
#define pokračuj continue

// ostatní klíčová slova
#define vrať return
#define navrať return
#define stálé static
#define stálý static
#define stálá static
#define neměnné const
#define neměnný const
#define neměnná const
#define jdido goto
#define velikost(x) sizeof(x)

#define hlavní main

// operátory
#define je ==
#define rovná ==
#define rovnáse ==
#define není !=
#define nerovná !=
#define nerovnáse !=

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
#define vcajku 1
#define blbě 0
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

// <string.h>
#define pamzkop(...) memccpy(__VA_ARGS__)
#define pamzna(...) memchr(__VA_ARGS__)
#define pampor(...) memcmp(__VA_ARGS__)
#define pamkop(...) memcpy(__VA_ARGS__)
#define pampřesuň(...) memmove(__VA_ARGS__)
#define pamnastav(...) memset(__VA_ARGS__)
// ŘEtězcový Ukazatel KOPíruj
#define řeukop(...) stpcpy(__VA_ARGS__)
#define řeučkop(...) stpncpy(__VA_ARGS__)
#define řeťpoj(...) strcat(__VA_ARGS__)
#define řeťzna(...) strchr(__VA_ARGS__)
#define řeťpor(...) strcmp(__VA_ARGS__)
// strcoll znamená STRing COLLate
#define řeťřaď(...) strcoll(__VA_ARGS__)
// _l znamená lokalizace
#define řeťřaď_l(...) strcoll_l(__VA_ARGS__)
#define řeťkop(...) strcpy(__VA_ARGS__)
// ŘEŤezcový Doplňkový RoZSaH (fonetický zápis řetězce)
// STRing Complemetary SPaN
#define řeťdrzsh(...) strcspn(__VA_ARGS__)
#define řeťzdv(...) strdup(__VA_ARGS__)
#define řeťchyba(...) strerror(__VA_ARGS__)
#define řeťchyba_l(...) strerror_l(__VA_ARGS__)
// Upřímně netuším, co to _r má být za slovo
#define řeťchyba_r(...) strerror_r(__VA_ARGS__)
#define řeťdél(...) strlen(__VA_ARGS__)
#define řeťčpoj(...) strncat(__VA_ARGS__)
#define řeťčpor(...) strncmp(__VA_ARGS__)
#define řeťčkop(...) strncpy(__VA_ARGS__)
#define řeťčzdv(...) strndup(__VA_ARGS__)
#define řeťčdél(...) strnlen(__VA_ARGS__)
//STRing Pointer BReaK - ŘEŤezcový Ukazatel ZLoM
#define řeťuzlm(...) strpbrk(__VA_ARGS__)
//string reverse char - řetězcový zpětný znal
#define řeťzzna(...) strrchr(__VA_ARGS__)
#define řeťznamení(...) strsignal(__VA_ARGS__)
#define řeťrzsh(...) strspn(__VA_ARGS__)
#define řeťřeť(...) strstr(__VA_ARGS__)
#define řeťžet(...) strtok(__VA_ARGS__)
// _r -> reentrant -> znovuvstupující
#define řeťžet_z(...) strtok_r(__VA_ARGS__)
// xfrm je zřejmě divná zkratka z transform
#define řeťzměň(...) strxfrm(__VA_ARGS__)
#define řeťzměň_l(...) strcfrm_l(__VA_ARGS__)

// <float.h>
#define PLV_SOUSTAVA FLT_RADIX
#define PLV_UDRŽ_ČÍS FLT_MANT_DIG
#define DVJ_UDRŽ_ČÍS DBL_MANT_DIG
#define DDVJ_UDRŽ_ČÍS LDBL_MANT_DIG
#define DESÍTKOVÝCH_ČÍS DECIMAL_DIG
#define PLV_ČÍS FLT_DIG
#define DVJ_ČÍS DBL_DIG
#define DDVJ_ČÍS LDBL_DIG
#define PLV_MIN_MOC FLT_MIN_EXP
#define DVJ_MIN_MOC DBL_MIN_EXP
#define DDVJ_MIN_MOC LDBL_MIN_EXP
#define PLV_MIN_10_MOC FLT_MIN_10_EXP
#define DVJ_MIN_10_MOC DBL_MIN_10_EXP
#define DDVJ_MIN_10_MOC LDBL_MIN_10_EXP
#define PLV_MAX_MOC FLT_MAX_EXP
#define DVJ_MAX_MOC DBL_MAX_EXP
#define DDVJ_MAX_MOC LDBL_MAX_EXP
#define PLV_MAX_10_MOC FLT_MAX_10_EXP
#define DVJ_MAX_10_MOC DBL_MAX_10_EXP
#define DDVJ_MAX_10_MOC LDBL_MAX_10_EXP
#define PLV_MAX FLT_MAX
#define DVJ_MAX DBL_MAX
#define DDVJ_MAX LDBL_MAX
#define PLV_EPSILON FLT_EPSILON
#define DVJ_EPSILON DBL_EPSILON
#define DDVJ_EPSILON LDBL_EPSILON
#define PLV_MIN FLT_MIN
#define DVJ_MIN DBL_MIN
#define DDVJ_MIN LDBL_MIN

// <math.h>
#define plovoucí_t float_t
#define dvojitý_t double_t
#define dvojité_t double_t
#define PLV_VYKON_ZPŮSOB FLT_EVAL_METHOD
#define pčroztřiď(x) fpclassify(x)
#define jekonečné(x) isfinite(x)
#define jevětší(x, y) isgreater(x, y)
#define jevětšírovno(x, y) isgreaterequal(x, y)
#define jeneko(x) isinf(x)
#define jemenší(x, y) isless(x, y)
#define jemenšírovno(x, y) islessequal(x, y)
#define jemenšívětší(x, y) islessgreater(x, y)
#define jenečíslo(x) isnan(x)
#define jenormální(x) isnormal(x)
#define jeneřaditelné(x, y) isunordered(x, y)
#define znaménkovýbit(x) signbit(x)
#define znamýnkovýbit(x) signbit(x)
#define M_2_2ODMPI M_2_SQRTPI
#define M_2ODM2 M_SQRT2
#define M_2ODM1_2 M_SQRT1_2
#define MAXPLOVOUCÍ MAXFLOAT
#define OBŘÍ_HOD HUGE_VAL
#define OBŘÍ_HODP HUGE_VALF
#define OBŘÍ_HODD HUGE_VALL
#define NEKONEČNO INFINITY
#define NEČÍSLO NAN
#define PČ_NEKONEČNÉ FP_INFINITE
#define PČ_NEČÍSLO FP_NAN
#define PČ_NORMÁLNÍ FP_NORMAL
#define PČ_PODNORMÁLNÍ FP_SUBNORMAL
#define PČ_NULA FP_ZERO
#define PČ_RYCHLÁ_PRS FP_FAST_FMA
#define PČ_RYCHLÁ_PRSP FP_FAST_FMAF
#define PČ_RYCHLÁ_PRSD FP_FAST_FMAL
#define PČ_ČLOGD0 FP_ILOGB0
#define PČ_ČLOGDNEČÍSLO FP_ILOGBNAN
#define MATIKA_CHYBČÍS MATH_ERRNO
#define MATIKA_CHYBCHYBA MATH_ERREXCEPT
#define matika_chybzpracování math_errhandling
#define acosp(x) acosf(x)
#define acoshp(x) acoshf(x)
#define acoshd(x) acoshl(x)
#define acosd(x) acosl(x)
#define asinp(x) asinf(x)
#define asinhp(x) asinhf(x)
#define asinhd(x) asinhl(x)
#define asind(x) asinl(x)
#define atan2p(x, y) atan2f(x, y)
#define atan2d(x, y) atan2l(x, y)
#define atanp(x) atanf(x)
#define atanhp(x) atanhf(x)
#define atanhd(x) atanhl(x)
#define atand(x) atanl(x)
#define třod(x) cbrt(x)
#define třodp(x) cbrtf(x)
#define třodd(x) cbrtl(x)
#define strop(x) ceil(x)
#define stropp(x) ceilf(x)
#define stropd(x) ceill(x)
#define zaokrouhlinahoru(x) ceil(x)
#define zaokrouhlinahorup(x) ceilf(x)
#define zaokrouhlinahorud(x) ceill(x)
#define kopírujznaménko(x, y) copysign(x, y)
#define kopírujznaménkop(x, y) copysignf(x, y)
#define kopírujznaménkod(x, y) copysignl(x, y)
#define cosp(x) cosf(x)
#define coshp(x) coshf(x)
#define coshd(x) coshl(x)
#define cosd(x) cosl(x)
#define chf(x) erf(x)
#define chfp(x) erff(x)
#define chfd(x) erfl(x)
#define chfd(x) erfc(x)
#define chfdp(x) erfcf(x)
#define chfdd(x) erfcl(x)
#define moc(x) exp(x)
#define mocp(x) expf(x)
#define mocd(x) expl(x)
#define moc2(x) exp2(x)
#define moc2p(x) exp2f(x)
#define moc2d(x) exp2l(x)
#define mocm1(x) expm1(x)
#define mocm1p(x) expm1f(x)
#define mocm1d(x) expm1l(x)
#define pabs(x) fabs(x)
#define pabsp(x) fabsf(x)
#define pabsd(x) fabsl(x)
#define prom(x) fdim(x)
#define promp(x) fdimf(x)
#define promd(x) fdiml(x)
#define podlaha(x) floor(x)
#define zaokrouhlidolů(x) floor(x)
#define podlahap(x) floorf(x)
#define podlahad(x) floorl(x)
#define zaokrouhlidolůp(x) floorf(x)
#define zaokrouhlidolůd(x) floorl(x)
#define prs(...) fma(__VA_ARGS__)
#define prsp(...) fmaf(__VA_ARGS__)
#define prsd(...) fmal(__VA_ARGS__)
#define pmax(x, y) fmax(x, y)
#define pmaxp(x, y) fmaxf(x, y)
#define pmaxd(x, y) fmaxl(x, y)
#define pmin(x, y) fmin(x, y)
#define pminp(x, y) fminf(x, y)
#define pmind(x, y) fminl(x, y)
#define pzby(x, y) fmod(x, y)
#define pzbyp(x, y) fmodf(x, y)
#define pzbyd(x, y) fmodl(x, y)
