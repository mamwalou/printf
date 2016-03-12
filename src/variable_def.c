#include "../inc/my_printf.h"

static t_tab    tab[LENGHT]=
{
    {0, len_t},
    {1, len_h},
    {2, len_l},
    {3, len_L},
    {4, len_j},
    {5, len_z},
    {6, len_hh},
    {7, len_ll},
};

void        *varibale_define(t_params *params)
{
    int     i;

    i = 0;
    while (i < LENGHT)
    {
        if (tab[i].f(params) < 1)
            return ;
    }
}
