#include "../czech.h"
#include <stdio.h>

číslo hlavní(prázdnota)
{
    neměnné číslo omezení = 100;

    pro (číslo i = 2; i < omezení; i++)
    {
        číslo prvočíslo = pravda;

        pro (číslo j = 2; j < i; j++)
        {
            jestli (i % j == 0)
            {
                prvočíslo = nepravda;
                rozbij;
            }
        }

        jestli (prvočíslo)
        {
            tisknif("%d je prvočíslo\n", i);
        }
    }

    vrať 0;
}
