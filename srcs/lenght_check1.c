/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:25:42 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/12 20:26:00 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static int		lenght_hh2(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 9 || sp == 10 || sp == 5)
	{
		var->var_unchar = (unsigned)va_arg(args->ap, int);
		ft_putnbr(var->var_unchar);
		return (ft_nbsize(var->var_unchar));
	}
	if (sp == 7)
	{
		var->var_unchar = (unsigned)va_arg(args->ap, int);
		return (con_octal(var->var_unchar, p));
	}
	var->var_unchar = (unsigned)va_arg(args->ap, int);
	if (sp == 11)
		return (con_hx(var->var_unchar, 0, p));
	else if (sp == 12)
		return (con_hx(var->var_unchar, 1, p));
	return (-1);
}

static int		lenght_hh1(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 3)
	{
		var->var_wint = va_arg(args->ap, wint_t);
		ft_putwchar(var->var_wint);
		return (ft_lenghtwchar(var->var_wint));
	}
	if (sp == 1)
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
	return (lenght_hh2(sp, args, var, p));
}

int				lenght_hh(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 4 || sp == 6)
	{
		var->var_signedc = (signed)va_arg(args->ap, int);
		ft_putnbr(var->var_signedc);
		return (ft_nbsize(var->var_signedc));
	}
	else if (sp == 8 || sp == 10 || sp == 5)
	{
		var->var_unsint = (unsigned)va_arg(args->ap, int);
		if (sp == 8)
			return (con_octal(var->var_unsint, p));
		else
		{
			ft_putnbr(var->var_unsint);
			return (ft_nbsize(var->var_unsint));
		}
	}
	return (lenght_hh1(sp, args, var, p));
}

static int		lenght_ll1(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp != 5 && sp != 8)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	if (sp == 5 || sp == 8)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		if (sp == 5)
		{
			ft_putnbr(var->var_unshort);
			return (ft_nbsize(var->var_unshort));
		}
		else if (sp == 8)
		{
			return (con_octal(var->var_unshort, p));
		}
	}
	return (-1);
}

int				lenght_ll(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 9)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (sp == 7 || sp == 11 || sp == 12)
	{
		var->var_unlonglong = va_arg(args->ap, unsigned long long);
		if (sp == 7)
			return (con_uloctal(var->var_unlonglong, p));
		else if (sp == 11)
			return (con_unlhx(var->var_unlonglong, 0, p));
		else
			return (con_unlhx(var->var_unlonglong, 1, p));
	}
	return (lenght_ll1(sp, args, var, p));
}
