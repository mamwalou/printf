/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:25:42 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:52:07 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static int			lenght_hh2(int specifier, t_args *args, t_tabvar *var)
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
	{
		return (convert_hx(var->var_unchar,
				ft_strnb(&var->var_unchar), 1));
	}
	return (-1);
}

static int			lenght_hh1(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 3)
	{
		var->var_wint = va_arg(args->ap, wint_t);
		ft_putwchar(var->var_wint);
		return (ft_lenghtwchar(var->var_wint));
	}
	if (specifier == 1)
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
	return (lenght_hh2(specifier, args, var));
}

int					lenght_hh(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 4 || specifier == 6)
	{
		var->var_signedc = (signed)va_arg(args->ap, int);
		ft_putnbr(var->var_signedc);
		return (ft_nbsize(var->var_signedc));
	}
	else if (specifier == 8 || specifier == 10 || specifier == 5)
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

static int			lenght_ll1(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier != 5 && specifier != 8)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
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

int					lenght_ll(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 9)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (specifier == 7 || specifier == 11 || specifier == 12)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		if (specifier == 7)
			return (convert_uloctal(var->var_unlonglong,
					ft_lenghtunlong(var->var_unlonglong)));
		else if (specifier == 11)
			return (convert_unlhx(var->var_unlonglong,
					ft_strnb(&var->var_unlonglong), 0));
		else
			return (convert_unlhx(var->var_unlonglong,
					ft_strnb(&var->var_unlonglong), 1));
	return (lenght_ll1(specifier, args, var));
}
