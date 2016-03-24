#include "../includes/my_printf.h"

void    display(void *var, t_params *params)
{
    if (params->specifier > 4)
        ft_putnbr(*(double*)var);
}
