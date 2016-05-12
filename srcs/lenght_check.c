#include "../includes/my_printf.h"

static int		lenght_l2(int specifier, t_args *args, t_tabvar *var)
{
	var->var_unlonglong = va_arg(args->ap, unsigned long long);
	if (specifier == 9)
	{
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (specifier == 7)
		return(convert_uloctal(var->var_unlonglong,
			 ft_lenghtunlong(var->var_unlonglong)));
	else if (specifier == 11)
		return (convert_unlhx(var->var_unlonglong,
			ft_lenghtunlong(var->var_unlonglong), 0));
	else if (specifier == 12)
		return (convert_unlhx(var->var_unlonglong,
			ft_lenghtunlong(var->var_unlonglong), 1));
	return (-1);
}

static int		lenght_l1(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 2)
	{
		var->var_wint = va_arg(args->ap, wint_t);
		ft_putwchar(var->var_wint);
		return (ft_lenghtwchar(var->var_wint));
	}
	else if (specifier == 10 || specifier == 5)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		ft_putnbr(var->var_unshort);
		return (ft_nbsize(var->var_unshort));

	}
	else if (specifier == 8)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		return (convert_octal(var->var_unshort, ft_strnb(&var->var_unshort)));
	}
	return (lenght_l2(specifier, args, var));
}

int		lenght_l(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 4 || specifier == 6)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	else if (specifier == 0)
	{
		if ((var->var_wstr = va_arg(args->ap, wchar_t *)) != NULL)
		{
			ft_putwstr(var->var_wstr);
			return (ft_lenghstrwchar(var->var_wstr));
		}
		else
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	return (lenght_l1(specifier, args, var));
}

int		lenght_L(int specifier, t_args *args, t_tabvar *var)
{
	(void)specifier;
	(void)args;
	(void)var;
	return (0);
}

int		lenght_j(int specifier, t_args *args, t_tabvar *var)
{
	(void)specifier;
	(void)args;
	(void)var;
	return (0);
}
