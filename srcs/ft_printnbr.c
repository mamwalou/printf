/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:57:04 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/18 15:57:06 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		printnbr(int nb, t_params *params)
{
	int ret;

	ret = 0;
	if (params->pos_nb && nb > 0 && params->flags != '0')
	{
		ft_putchar('+');
		ft_putnbr(nb);
		ret++;
		return (ft_nbsize(nb) + ret);
	}
	if ((((int)ft_nbsize(nb) > params->count_flags) && (params->tflags != 't')))
	{
		if (params->pos_nb && nb >= 0)
		{
			ft_putchar('+');
			ft_putnbr(nb);
			return (ft_nbsize(nb) + ret + params->pos_nb);
		}
		ft_putnbr(nb);
		return (ft_nbsize(nb) + ret);
	}
	if (params->flags == '0' || params->flags == ' ' || params->tflags == 't')
		return (space_print(params, nb) + ret);
	return (0);
}
