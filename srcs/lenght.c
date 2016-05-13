/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:20:19 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:43:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int			str_check(const char *str)
{
	int i;

	i = 0;
	if (str[i] == 'h' && str[i + 1] == 'h')
		return (4);
	else if (str[i] == 'l' && str[i + 1] == 'l')
		return (5);
	return (0);
}

int 		lenght_gest(const char *str)
{
	char	tab[LENGHT];
	int		i;

	tab[0] = 'h';
	tab[1] = 'l';
	tab[2] = 'j';
	tab[3] = 'z';
	if ((i = str_check(str)) > 0)
		return (i);
	else
	{
		while (i <= 5)
		{
			if (tab[i] == *str)
				return (i);
			i++;
		}
	}
	return (LENGHT + 1);
}
