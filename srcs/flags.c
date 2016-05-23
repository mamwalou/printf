/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:26:07 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/23 19:02:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int			specifier(char format)
{
	int tab[SPECIFIER];
	int i;

	tab[0] = 's';
	tab[1] = 'S';
	tab[2] = 'c';
	tab[3] = 'C';
	tab[4] = 'd';
	tab[5] = 'D';
	tab[6] = 'i';
	tab[7] = 'o';
	tab[8] = 'O';
	tab[9] = 'u';
	tab[10] = 'U';
	tab[11] = 'x';
	tab[12] = 'X';
	tab[13] = 'p';
	i = 0;
	while(i < SPECIFIER)
	{
		if (format == tab[i])
			return (i);
		i++;
	}
	return (SPECIFIER);
}

int			flags(const char *str, int pos, t_params *params)
{
	int i;
	int count;
	int neg;

	neg = 0;
	count = 1;
	i = pos;
	if (str[pos] == '-')
	{
		neg = 1;
		pos++;
	}
	if (ft_isdigit(str[pos]))
	{
		while (ft_isdigit(str[pos]) > 0)
		{
			params->count_flags = params->count_flags * count + (str[pos] - 48);
			count = 10;
			pos++;
		}
		if (neg)
			params->count_flags = -params->count_flags;
		return(ft_nbsize(params->count_flags));
	}
	while (str[i] == ' ')
	{
		params->count_flags++;
		i++;
	}
	return (params->count_flags);
}

int			init_width(const char *str, int pos, t_params *params)
{
	(void)params;
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
