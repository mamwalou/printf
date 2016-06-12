/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:25:32 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/12 20:25:59 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static int		lenght_l2(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	var->var_unlonglong = va_arg(args->ap, unsigned long long);
	if (sp == 9)
	{
		ft_printunlong(var->var_unlonglong);
		return (ft_lenghtunlong(var->var_unlonglong));
	}
	else if (sp == 7)
		return (con_uloctal(var->var_unlonglong, p));
	else if (sp == 11)
		return (con_unlhx(var->var_unlonglong, 0, p));
	else if (sp == 12)
		return (con_unlhx(var->var_unlonglong, 1, p));
	return (-1);
}

static int		lenght_l1(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	if (sp == 2)
	{
		var->var_wint = va_arg(args->ap, wint_t);
		ft_putwchar(var->var_wint);
		return (ft_lenghtwchar(var->var_wint));
	}
	else if (sp == 10 || sp == 5)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		ft_putnbr(var->var_unshort);
		return (ft_nbsize(var->var_unshort));
	}
	else if (sp == 8)
	{
		var->var_unshort = (unsigned)va_arg(args->ap, int);
		return (con_octal(var->var_unshort, p));
	}
	return (lenght_l2(sp, args, var, p));
}

int				lenght_l(int sp, t_args *args, t_tabvar *var, t_params *p)
{
	void		*ptr;

	if (sp == 4 || sp == 6)
	{
		var->var_longlong = va_arg(args->ap, long long);
		ft_printlong(var->var_longlong);
		return (ft_lenghtlong(var->var_longlong));
	}
	else if (sp == 0)
	{
		if ((var->var_wstr = va_arg(args->ap, wchar_t *)) != NULL)
		{
			ft_putwstr(var->var_wstr);
			return (ft_lenghstrwchar(var->var_wstr));
		}
	}
	if (sp == 13)
	{
		ptr = va_arg(args->ap, void *);
		return (ft_print_memory(p, ptr));
	}
	return (lenght_l1(sp, args, var, p));
}

int				lenght_j1(int sp, t_args *args, t_tabvar *var, t_params *p)
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

int				lenght_j(int sp, t_args *args, t_tabvar *var, t_params *p)
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
	return (lenght_j1(sp, args, var, p));
}
