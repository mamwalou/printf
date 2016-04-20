#include "../includes/my_printf.h"

int     specifier_integer(t_params *params, t_args *args)
{
    int     i;

	i = 0;
    if (params->lenght > LENGHT)
    {
        i = va_arg(args->ap, int);
        ft_putnbr(i);
    }
    return (ft_nbsize(i));
}

int     specifier_spint(t_params *params, t_args *args)
{
    unsigned int uni;

	uni = 0;
    if (params->lenght > LENGHT)
    {
        uni = (unsigned)va_arg(args->ap, int);
        if (params->specifier == 6)
            convert_octal(uni);
        else if (params->specifier == 10)
            convert_hexlow(uni, ft_strnb(&uni), 0);
		else if (params->specifier == 11)
			convert_hexlow(uni, ft_strnb(&uni), 1);
        else
			ft_putnbr(uni);
    }
    return (ft_nbsize(uni));
}

int     specifier_float(t_params *params, t_args *args)
{
    double db;

	db = 0;
    if (params->lenght > LENGHT)
    {
        db = va_arg(args->ap, double);
        display(&db, params);
    }
    return (ft_nbsize(db));
}


int		print_add(t_params *params, t_args *args)
{
	void 	*p;
	(void)params;

	p = va_arg(args->ap, void *);
	return (ft_print_memory(p, sizeof(&p)));
}
