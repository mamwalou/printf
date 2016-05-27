/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:25:42 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/27 22:29:26 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static int			lenght_hh2(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 9 || spe == 10 || spe == 5)
	{
		var->var_unchar = (unsigned)va_arg(args->ap, int);
		ft_putnbr(var->var_unchar);
		return (ft_nbsize(var->var_unchar));
	}
	if (spe == 7)
	{
		var->var_unchar = (unsigned)va_arg(args->ap, int);
		return (con_octal(var->var_unchar, params));
	}
	var->var_unchar = (unsigned)va_arg(args->ap, int);
	if (spe == 11)
		return (con_hx(var->var_unchar, 0, params));
	else if (spe == 12)
		return (con_hx(var->var_unchar, 1, params));
	return (-1);
}

static int			lenght_hh1(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 3)
	{
		var->var_wint = va_arg(args->ap, wint_t);
		ft_putwchar(var->var_wint);
		return (ft_lenghtwchar(var->var_wint));
	}
	if (spe == 1)
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
	return (lenght_hh2(spe, args, var, params));
}

int					lenght_hh(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 4 || spe == 6)
	{
		var->var_signedc = (signed)va_arg(args->ap, int);
		ft_putnbr(var->var_signedc);
		return (ft_nbsize(var->var_signedc));
	}
	else if (spe == 8 || spe == 10 || spe == 5)
	{
		var->var_unsint = (unsigned)va_arg(args->ap, int);
		if (spe == 8)
			return (con_octal(var->var_unsint, params));
		else
		{
			ft_putnbr(var->var_unsint);
			return (ft_nbsize(var->var_unsint));
		}
	}
	return (lenght_hh1(spe, args, var, params));
}

static int			lenght_ll1(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe != 5 && spe != 8)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	if (spe == 5 || spe == 8)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		if (spe == 5)
		{
			ft_putnbr(var->var_unshort);
			return (ft_nbsize(var->var_unshort));
		}
		else if (spe == 8)
		{
			return (con_octal(var->var_unshort, params));
		}
	}
	return (-1);
}

int					lenght_ll(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 9)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (spe == 7 || spe == 11 || spe == 12)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		if (spe == 7)
			return (con_uloctal(var->var_unlonglong, params));
		else if (spe == 11)
			return (con_unlhx(var->var_unlonglong, 0, params));
		else
			return (con_unlhx(var->var_unlonglong, 1, params));
	}
	return (lenght_ll1(spe, args, var, params));
}
