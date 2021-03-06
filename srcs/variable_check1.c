/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_check1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 16:01:34 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/18 16:01:36 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int			specifier_integer(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght == LENGHT)
	{
		if (params->specifier != 5 && params->specifier != 8)
		{
			var->var_int = va_arg(args->ap, int);
			return (printnbr(var->var_int, params));
		}
		else if (params->specifier == 5 || params->specifier == 8)
		{
			var->var_longlong = va_arg(args->ap, long long);
			if (params->specifier == 5)
			{
				ft_printlong(var->var_longlong);
				return (ft_lenghtlong(var->var_longlong));
			}
			else if (params->specifier == 8)
				return (con_loctal(var->var_longlong, params));
		}
	}
	return (-1);
}

int			specifier_spint(t_params *params, t_args *args, t_tabvar *var)
{
	var->var_unsint = (unsigned)va_arg(args->ap, int);
	if (params->specifier == 7)
		return (con_octal(var->var_unsint, params));
	else if (params->specifier == 11)
		return (con_hx(var->var_unsint, 0, params));
	else if (params->specifier == 12)
		return (con_hx(var->var_unsint, 1, params));
	else if (params->specifier == 9)
		ft_printunint(var->var_unsint);
	if (var->var_unsint == 0)
		return (1);
	return (ft_lenghtunint(var->var_unsint));
}

int			specifier_slong(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght == LENGHT)
	{
		if (params->specifier == 10)
		{
			var->var_unlonglong = va_arg(args->ap, unsigned long long);
			ft_printunlong(var->var_unlonglong);
			return (ft_lenghtunlong(var->var_unlonglong));
		}
	}
	return (ft_nbsize(var->var_double));
}

int			print_add(t_params *params, t_args *args, t_tabvar *var)
{
	void	*p;

	(void)var;
	p = va_arg(args->ap, void *);
	return (ft_print_memory(params, p));
}
