#include "../includes/my_printf.h"

int		lenght_z(int specifier, t_args *args, t_tabvar *var)
{
	(void)specifier;
	(void)args;
	(void)var;
	return (0);
}
int		lenght_T(int specifier, t_args *args, t_tabvar *var)
{
	(void)specifier;
	(void)args;
	(void)var;
	return (0);
}

static int		lenght_hh1(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 9 || specifier == 10 || specifier == 5)
	{
		var->var_unchar = (unsigned)va_arg(args->ap, int);
		ft_putnbr(var->var_unchar);
		return (ft_nbsize(var->var_unchar));
	}
	if (specifier == 7)
	{
		var->var_unchar = (unsigned)va_arg(args->ap, int);
		return (convert_octal(var->var_unchar,
				ft_strnb(&var->var_unchar)));
	}
	var->var_unchar = (unsigned)va_arg(args->ap, int);
	if (specifier == 11)
		return (convert_hx(var->var_unchar,
				ft_strnb(&var->var_unchar), 0));
	else if (specifier == 12)
		return (convert_hx(var->var_unchar,
				ft_strnb(&var->var_unchar), 1));
	return (-1);
}

int				lenght_hh(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 4 || specifier == 6)
	{
		var->var_signedc = (signed)va_arg(args->ap, int);
		ft_putnbr(var->var_signedc);
		return (ft_nbsize(var->var_signedc));
	}
	else if (specifier == 8 || specifier == 10)
	{
		var->var_unsint = (unsigned)va_arg(args->ap, int);
		if (specifier == 8)
			return (convert_octal(var->var_unsint,
					ft_strnb(&var->var_unsint)));
		else
		{
			ft_putnbr(var->var_unsint);
			return (ft_nbsize(var->var_unsint));
		}
	}
	return (lenght_hh1(specifier, args, var));
}

static int		lenght_ll1(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 5 || specifier == 8)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		if (specifier == 5)
		{
			ft_putnbr(var->var_unshort);
			return (ft_nbsize(var->var_unshort));
		}
		else if (specifier == 8)
		{
			return (convert_octal(var->var_unshort,
				 ft_strnb(&var->var_unshort)));
		}
	}
	return (-1);
}

int		lenght_ll(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 9)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		ft_printunlong(var->var_unlonglong);
		return(ft_lenghtunlong(var->var_unlonglong));
	}
	else if (specifier == 7 || specifier == 11 || specifier == 12)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		if (specifier == 7)
			return(convert_uloctal(var->var_unlonglong,
			 	ft_lenghtunlong(var->var_unlonglong)));
		else if (specifier == 11)
			return (convert_unlhx(var->var_unlonglong,
				ft_strnb(&var->var_unlonglong), 0));
		else
			return (convert_unlhx(var->var_unlonglong,
			 	ft_strnb(&var->var_unlonglong), 1));

	}
	else if (specifier != 5 && specifier != 8)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}

	return (lenght_ll1(specifier, args, var));
}


int		lenght_h(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 4 || specifier == 6)
	{
		var->var_short = va_arg(args->ap, int);
		ft_putnbr(var->var_short);
		return (ft_nbsize(var->var_short));
	}
	var->var_unshort = (unsigned)va_arg(args->ap, int);
	if (specifier == 9 || specifier == 10 || specifier == 5)
	{
		ft_putnbr(var->var_unshort);
		return (ft_nbsize(var->var_unshort));
	}
	else if (specifier == 7 || specifier == 8)
		return (convert_octal(var->var_unshort,
				ft_strnb(&var->var_unshort)));
	else if (specifier == 11)
		return (convert_hx(var->var_unshort,
				ft_strnb(&var->var_unshort), 0));
	else if (specifier == 12)
		return (convert_hx(var->var_unshort,
				ft_strnb(&var->var_unshort), 1));
	return (-1);
}
