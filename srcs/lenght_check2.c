/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:20:36 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/27 22:27:55 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int					lenght_h(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 4 || spe == 6)
	{
		var->var_short = va_arg(args->ap, int);
		ft_putnbr(var->var_short);
		return (ft_nbsize(var->var_short));
	}
	var->var_unshort = (unsigned)va_arg(args->ap, int);
	if (spe == 9 || spe == 10 || spe == 5)
	{
		ft_putnbr(var->var_unshort);
		return (ft_nbsize(var->var_unshort));
	}
	else if (spe == 7 || spe == 8)
		return (con_octal(var->var_unshort, params));
	else if (spe == 11)
		return (con_hx(var->var_unshort, 0, params));
	else if (spe == 12)
		return (con_hx(var->var_unshort, 1, params));
	return (-1);
}

static int			lenght_z2(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 9 || spe == 7 || spe == 11 || spe == 12)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		if (spe == 7)
			return (con_uloctal(var->var_unlonglong, params));
		else if (spe == 11)
			return (con_unlhx(var->var_unlonglong, 0, params));
		else if (spe == 12)
			return (con_unlhx(var->var_unlonglong, 1, params));
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (spe != 5 && spe != 8)
	{
		var->var_int = va_arg(args->ap, int);
		ft_putnbr(var->var_int);
		return (ft_nbsize(var->var_int));
	}
	return (-1);
}

int					lenght_z(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 5 || spe == 4 || spe == 6)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	else if (spe == 8)
	{
		var->var_longlong = va_arg(args->ap, long long);
		return (con_loctal(var->var_longlong, params));
	}
	return (lenght_z2(spe, args, var, params));
}
