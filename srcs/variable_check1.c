#include "../includes/my_printf.h"

int     specifier_integer(t_params *params, t_args *args, t_tabvar *var)
{
    if (params->lenght > LENGHT || params->specifier != 5)
    {
        var->var_unsint = va_arg(args->ap, int);
        ft_putnbr(var->var_unsint);
		return (ft_nbsize(var->var_unsint));
    }
	if (params->specifier == 5)
	{
		var->var_long = (long)va_arg(args->ap, int);
		ft_putnbr(var->var_long);
		return (ft_nbsize(var->var_long));
	}
	return(-1);
}

int     specifier_spint(t_params *params, t_args *args, t_tabvar *var)
{

    if (params->lenght > LENGHT)
    {
        var->var_unsint = (unsigned)va_arg(args->ap, int);
        if (params->specifier == 7 || params->specifier == 8)
            convert_octal(var->var_unsint);
        else if (params->specifier == 11)
            convert_hexlow(var->var_unsint, ft_strnb(&var->var_unsint), 0);
		else if (params->specifier == 12)
			convert_hexlow(var->var_unsint, ft_strnb(&var->var_unsint), 1);
        else
			ft_putnbr(var->var_unsint);
		if (var->var_unsint == 0)
			return(1);
		return (ft_nbsize(var->var_unsint));
    }
	return (-1);
}

int     specifier_float(t_params *params, t_args *args, t_tabvar *var)
{

    if (params->lenght > LENGHT)
    {
        var->var_double = va_arg(args->ap, double);
    }
    return (ft_nbsize(var->var_double));
}


int		print_add(t_params *params, t_args *args, t_tabvar *var)
{
	void 	*p;
	(void)params;
	(void)var;
	p = va_arg(args->ap, void *);
	return (ft_print_memory(p, sizeof(&p)));
}
