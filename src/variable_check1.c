#include "../inc/my_printf.h"

int        len_j(t_params *params)
{
    intmax_t intmaxt;

    intmaxt = 0;
    params->var = &intmaxt;
    return (0);
}

int        len_hh(t_params *params)
{
    if (params->specifier == 4 || params->specifier == 5)
    {
        signed char sichar;

        sichar = 0;
        params->var = &sichar;
    }
    else if (params->specifier >= 8 && params->specifier <= 11)
    {
        unsigned char uchar;

        uchar = 0;
        params->var = &uchar;
    }
    return (0);
}

int        len_ll(t_params *params)
{
    if (params->specifier == 4 || params->specifier == 5)
    {
        long long int llint;

        llint = 0;
        params->var = &llint;
    }
    if (params->specifier >= 8 && params->specifier <= 11)
    {
        unsigned long long int ullint;

        ullint = 0;
        params->var = &ullint;
    }
    return (0);
}
