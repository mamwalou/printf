/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:25:32 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/27 22:32:04 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static int		lenght_l2(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	var->var_unlonglong = va_arg(args->ap, unsigned long long);
	if (spe == 9)
	{
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (spe == 7)
		return (con_uloctal(var->var_unlonglong, params));
	else if (spe == 11)
		return (con_unlhx(var->var_unlonglong, 0, params));
	else if (spe == 12)
		return (con_unlhx(var->var_unlonglong, 1, params));
	return (-1);
}

static int		lenght_l1(int spe, t_args *args, t_tabvar *var, t_params *params)
{
	if (spe == 2)
	{
		var->var_wint = va_arg(args->ap, wint_t);
		ft_putwchar(var->var_wint);
		return (ft_lenghtwchar(var->var_wint));
	}
	else if (spe == 10 || spe == 5)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		ft_putnbr(var->var_unshort);
		return (ft_nbsize(var->var_unshort));
	}
	else if (spe == 8)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		return (con_octal(var->var_unshort, params));
	}
	return (lenght_l2(spe, args, var, params));
}

int				lenght_l(int spe, t_args *args, t_tabvar *var, t_params *params)
{

	if (spe == 4 || spe == 6)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	else if (spe == 0)
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
	if (spe == 13)
	{
		void *p;
		p = va_arg(args->ap, void *);
		return (ft_print_memory(params ,p));
	}
	return (lenght_l1(spe, args, var, params));
}

int				lenght_j1(int spe, t_args *args, t_tabvar *var, t_params *params)
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

int				lenght_j(int spe, t_args *args, t_tabvar *var, t_params *params)
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
	return (lenght_j1(spe, args, var, params));
}
