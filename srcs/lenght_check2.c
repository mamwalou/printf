/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:20:36 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 18:04:39 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int					lenght_h(int specifier, t_args *args, t_tabvar *var)
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
	{
		return (convert_hx(var->var_unshort,
				ft_strnb(&var->var_unshort), 1));
	}
	return (-1);
}

static int			lenght_z2(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 9 || specifier == 7 || specifier == 11 || specifier == 12)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		if (specifier == 7)
			return (convert_uloctal(var->var_unlonglong,
					ft_lenghtunlong(var->var_unlonglong)));
		else if (specifier == 11)
			return (convert_unlhx(var->var_unlonglong,
					ft_lenghtunlong(var->var_unlonglong), 0));
		else if (specifier == 12)
		{
			return (convert_unlhx(var->var_unlonglong,
					ft_lenghtunlong(var->var_unlonglong), 1));
		}
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (specifier != 5 && specifier != 8)
	{
		var->var_int = va_arg(args->ap, int);
		ft_putnbr(var->var_int);
		return (ft_nbsize(var->var_int));
	}
	return (-1);
}

int					lenght_z(int specifier, t_args *args, t_tabvar *var)
{
	if (specifier == 5 || specifier == 4 || specifier == 6)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	else if (specifier == 8)
	{
		var->var_longlong = va_arg(args->ap, long long);
		return (convert_loctal(var->var_longlong,
				ft_lenghtlong(var->var_longlong)));
	}
	return (lenght_z2(specifier, args, var));
}
