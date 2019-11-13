#ifndef CZECH_H_
#define CZECH_H_

//modifikátory
#define nehybný     static
#define brusle      inline
#define měňavec     volatile
#define autobus     auto
#define venkovní    extern

//řídící struktury
#define běžna       goto
#define když        if
#define takne       else
#define dělej       do
#define dokud       while
#define pro         for
#define rozchoďit   continue
#define rozhodit    break
#define vrať        return
#define přepínač    switch
#define případ      case
#define výchozí     default

//práce s typy
#define rozměr      sizeof
#define novytyp     typedef

#define skladba     struct
#define výčet       enum
#define CCCP        union

//datové typy
#define SOUBOR      FILE
#define rozhodovák  bool
#define neměnný     const
#define podepsaný   signed
#define nepodepsaný unsigned
#define prázdno     void
#define tuplák      double
#define plovák      float
#define čís         int
#define znak        char
#define kraťas      short
#define dlouhán     long
#define hafodlouhán long long

//definované hodnoty
#define nabeton     true
#define nepravda    false
#define NIC         NULL

#define stdven      stdout
#define stdchyb     stderr
#define stddovnitř  stdin

//funkce
#define hlavní(...) main(__VA_ARGS__)  
#define piš(...)    printf(__VA_ARGS__)
#define fpiš(...)   fprintf(__VA_ARGS__)
#define fpiš(...)   fprintf(__VA_ARGS__)

#endif
