#include "../inc/my_printf.h"

int        len_t(t_params *params)
{
    if (params->lenght == 0)
    {
        ptrdiff_t ptrdif;

        ptrdif = 0;
        params->var = &ptrdif;
        return (1);
    }
    return (0);
}

int        len_h(t_params *params)
{
    return (0);
}

int        len_l(t_params *params)
{
    return (0);
}

int        len_L(t_params *params)
{
    return (0);
}

int        len_z(t_params *params)
{
    size_t sizet;

    sizet = 0;
    params->var = &sizet;
    return (0);
}
