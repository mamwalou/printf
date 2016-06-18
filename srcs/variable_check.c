/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 16:00:41 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/18 16:00:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int			specifier_s(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght == LENGHT)
	{
		if ((var->var_str = va_arg(args->ap, char*)) != NULL)
			return (ft_printstr(var->var_str, params));
		else
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	return (ft_strlen(var->var_str));
}

int			specifier_ss(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght == LENGHT)
	{
		if ((var->var_wstr = va_arg(args->ap, wchar_t *)) != NULL)
			return (ft_printwchar(var->var_wstr, params));
		else
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	return (-1);
}

int			specifier_c(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght == LENGHT)
	{
		var->var_c = va_arg(args->ap, int);
		return (ft_printchar(var->var_c, params));
	}
	return (-1);
}

int			specifier_cc(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght == LENGHT)
	{
		var->var_wint = va_arg(args->ap, wint_t);
		ft_putwchar(var->var_wint);
		return (ft_lenghtwchar(var->var_wint));
	}
	return (-1);
}
