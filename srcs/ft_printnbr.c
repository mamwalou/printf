/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:09:02 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/11 17:23:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		printnbr(int nb, t_params *params)
{
	int ret;

	ret = 0;
	if (params->pos_nb && nb > 0)
	{
		ft_putchar('+');
		ret++;
	}
	if ((((int)ft_nbsize(nb) > params->count_flags) && (params->flags != 't')))
	{
		ft_putnbr(nb);
		return (ft_nbsize(nb) + ret);
	}
	if (params->flags == '0' || params->flags == ' ' || params->flags == 't')
		return (space_print(params, nb) + ret);
	return (0);
}
