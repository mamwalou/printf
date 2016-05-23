/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:09:02 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/23 20:22:39 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		printnbr(int nb, t_params *params)
{
	int count;

	if (params->count_flags)
	{
		count = params->count_flags - ft_nbsize(nb);
		if (count < 0)
		{
			ft_putnbr(nb);
			return (ft_nbsize(nb));
		}
		while (count--)
			ft_putchar(' ');
		ft_putnbr(nb);
		return (params->count_flags);
	}
	else
		ft_putnbr(nb);
	return (ft_nbsize(nb));
}

int		ft_printchar(char c, t_params *params)
{
	int count;

	if (params->count_flags)
	{
		count = params->count_flags - 1;
		if (count < 0)
		{
			ft_putchar(c);
			return (1);
		}
		while (count--)
			ft_putchar(' ');
		ft_putchar(c);
		return (params->count_flags);
	}
	else
		ft_putchar(c);
	return (1);
}

int		ft_printwchar(wchar_t *wstr, t_params *params)
{
	int count;

	if (params->count_flags)
	{
		count = params->count_flags - ft_lenghstrwchar(wstr);
		if (params->count_flags < 0)
		{
			count = params->count_flags;
			params->count_flags = -params->count_flags;
			ft_putwstr(wstr);
			while (count++)
				ft_putchar(' ');
			return (params->count_flags);
		}
		while (count--)
			ft_putchar(' ');
		ft_putwstr(wstr);
		return (params->count_flags);
	}
	else
		ft_putwstr(wstr);
	return (ft_lenghstrwchar(wstr));
}
