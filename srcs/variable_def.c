#include "../includes/my_printf.h"

static t_tab    tab[SPECIFIER]=
{
    {0, specifier_s},
    {1, specifier_S},
    {2, specifier_c},
    {3, specifier_C},
    {4, specifier_integer},
    {5, specifier_integer},
    {6, specifier_spint},
    {7, specifier_spint},
    {8, specifier_spint},
    {9, specifier_spint},
    {10, specifier_spint},
	{11, specifier_spint},
	{12, print_add},
    {13, specifier_float},
};

int        my_printf(t_params *params, t_args *args)
{
    int     i;

    i = 0;
    while (tab[i].i != params->specifier && i <= SPECIFIER)
        i++;
	ft_putnbr(i);
    if (i <= SPECIFIER)
        return (tab[i].f(params, args));
	return (0);
}
