#include "../inc/my_printf.h"

static void     print_integer_simply(t_params *params, t_args *args, void *var)
{

    /*if (params->specifier == 8)
    {
        v->unint = va_arg(args->ap, unsigned int);
        ft_putnbr(v->unint);
    }
    if (params->specifier == 6)
    {
        v->unint = va_arg(args->ap, unsigned int);
        convert_octal(v->unint);
    }
    if (params->specifier == 10)
    {
        v->unint = va_arg(args->ap, unsigned int);
        //convert_hexlow(v->unint);
    }*/
}

static int     print_integer(t_params *params, t_args *args, void *var)
{
    if (params->specifier >= 4 && params->specifier <= 13)
    {
        if (!params->lenght)
            print_integer_simply(params, args, var);
    }

}

void    ft_printf(t_params params, t_args *args)
{
    varibale_define(&params, args);
    //print_integer(&params, args, var);
    /*print_floating(&params, args, format);
    print_string(&params, args, format);*/
}
