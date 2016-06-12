/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:20:36 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/12 20:26:00 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int				lenght_h(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 4 || sp == 6)
	{
		var->var_short = va_arg(args->ap, int);
		ft_putnbr(var->var_short);
		return (ft_nbsize(var->var_short));
	}
	var->var_unshort = (unsigned)va_arg(args->ap, int);
	if (sp == 9 || sp == 10 || sp == 5)
	{
		ft_putnbr(var->var_unshort);
		return (ft_nbsize(var->var_unshort));
	}
	else if (sp == 7 || sp == 8)
		return (con_octal(var->var_unshort, p));
	else if (sp == 11)
		return (con_hx(var->var_unshort, 0, p));
	else if (sp == 12)
		return (con_hx(var->var_unshort, 1, p));
	return (-1);
}

static int		lenght_z2(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 9 || sp == 7 || sp == 11 || sp == 12)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		if (sp == 7)
			return (con_uloctal(var->var_unlonglong, p));
		else if (sp == 11)
			return (con_unlhx(var->var_unlonglong, 0, p));
		else if (sp == 12)
			return (con_unlhx(var->var_unlonglong, 1, p));
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (sp != 5 && sp != 8)
	{
		var->var_int = va_arg(args->ap, int);
		ft_putnbr(var->var_int);
		return (ft_nbsize(var->var_int));
	}
	return (-1);
}

int				lenght_z(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 5 || sp == 4 || sp == 6)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	else if (sp == 8)
	{
		var->var_longlong = va_arg(args->ap, long long);
		return (con_loctal(var->var_longlong, p));
	}
	return (lenght_z2(sp, args, var, p));
}
