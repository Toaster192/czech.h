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
