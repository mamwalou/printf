#include "../inc/my_printf.h"

int        len_t(t_params *params, t_args *args)
{
    ptrdiff_t ptrdiff;

    if (params->specifier == 4)
    {
        ptrdiff = (ptrdiff_t)va_arg(args->ap, int);
        ft_putnbr(ptrdiff);
    }
    return (0);
}

int        len_h(t_params *params, t_args *args)
{
    short int shortint;

    if (params->specifier == 4)
    {
        shortint = (short)va_arg(args->ap, int);
        ft_putnbr(shortint);
    }
    return (0);
}

int        len_l(t_params *params, t_args *args)
{
    return (0);
}

int        len_L(t_params *params, t_args *args)
{
    return (0);
}

int        len_z(t_params *params, t_args *args)
{
    return (0);
}
