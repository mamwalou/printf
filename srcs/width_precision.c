/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:38:35 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/11 17:32:13 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int			init_width(const char *str, int pos, t_params *params)
{
	(void)params;
	if (str[pos] == '#')
	{
		params->flags = '#';
		params->count_flags = 1;
		return (1);
	}
	else if (str[pos] == '-' && !ft_isdigit(str[pos + 1]))
	{
		params->neg_nb = 1;
		return (1);
	}
	else if (str[pos] == '+' && !ft_isdigit(str[pos + 1]))
	{
		params->pos_nb = 1;
		return (1);
	}
	if (str[pos] == '*')
		return (0);
	return (0);
}

int			get_precision(const char *str, int pos, t_params *params)
{
	int		tmp;

	if (str[pos] == '*')
		return (0);
	if (ft_isdigit(str[pos]) > 0)
	{
		tmp = str[pos] - 48;
		if (params->precision != 0)
			params->precision = tmp + params->precision * 10;
		else
			params->precision = tmp;
		return (1);
	}
	return (0);
}
