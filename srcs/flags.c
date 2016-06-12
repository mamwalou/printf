/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:26:07 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/12 19:58:07 by sbeline          ###   ########.fr       */
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
	while (i < SPECIFIER)
	{
		if (format == tab[i])
			return (i);
		i++;
	}
	return (SPECIFIER);
}

int			define_width(const char *str, int pos, t_params *params)
{
	int ret;

	ret = 0;
	if (str[pos] == '-')
	{
		params->neg = 1;
		ret++;
	}
	else if (str[pos] == '+')
	{
		params->pos = 1;
		ret++;
	}
	else if (!params->flags)
		params->flags = ' ';
	return (ret);
}

int			flags(const char *str, int pos, t_params *params)
{
	int count;
	int ret;

	pos += define_width(str, pos, params);
	if (params->count_flags)
		return (0);
	if (ft_isdigit(str[pos]) && str[pos] != '0')
	{
		ret = 0;
		while (ft_isdigit(str[pos]) > 0)
		{
			params->count_flags = params->count_flags * count + (str[pos] - 48);
			count = 10;
			ret++;
			pos++;
		}
		return (ret + params->neg + params->pos);
	}
	else
	{
		params->neg = 0;
		params->pos = 0;
	}
	return (0);
}

int			space(const char *str, int pos, t_params *params)
{
	int tmp;
	int count;

	if (str[pos] == ' ')
	{
		if (str[pos] == ' ')
			params->tflags = 't';
		tmp = 0;
		while (str[pos] == ' ')
		{
			pos++;
			tmp++;
			params->count_tflags++;
		}
		return (tmp);
	}
	else if (str[pos] == '0')
	{
		if (str[pos] == '0')
			params->flags = '0';
		if (!ft_isdigit(str[pos]))
			return (0);
		pos++;
		tmp = 1;
		count = 0;
		while (ft_isdigit(str[pos]) > 0)
		{
			params->count_flags = params->count_flags * count + (str[pos] - 48);
			count = 10;
			tmp++;
			pos++;
		}
		return (tmp);
	}
	return (0);
}
