/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:26:07 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/30 19:49:09 by sbeline          ###   ########.fr       */
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

int			define_width(const char *str, int pos, t_params *params)
{
	if (str[pos] == '0')
		params->flags = '0';
	else
		params->flags = ' ';
	return (0);
}

int			flags(const char *str, int pos, t_params *params)
{
	int count;
	int ret;

	count = 0;
	pos += define_width(str, pos, params);
	if (str[pos] == '-')
	{
		params->neg = 1;
		pos++;
	}
	if (ft_isdigit(str[pos]))
	{
		ret = 0;
		while (ft_isdigit(str[pos]) > 0)
		{
			params->count_flags = params->count_flags * count + (str[pos] - 48);
			count = 10;
			ret++;
			pos++;
		}
		return (ret + params->neg);
	}
	return (0);
}

int			space(const char *str, int pos, t_params *params)
{
	int tmp;

	tmp = 0;
	if (str[pos] == ' ')
	{
		while (str[pos] == ' ')
		{
			pos++;
			tmp++;
		}
		params->flags = 't';
		params->count_flags++;
	}
	return (tmp);
}
