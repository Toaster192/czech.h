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
// #define chfd(x) erfl(x) TODO: fix duplicate
// #define chfd(x) erfc(x)
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
