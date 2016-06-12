/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 15:44:22 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/12 19:06:30 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		space_print(t_params *params, int nb)
{
	int ret;

	ret = 0;
	if (params->pos_nb)
		ft_putchar('+');
	if (!params->neg)
	{
		if (nb < 0 && !(params->tflags))
		{
			nb = -nb;
			if (params->flags == '0')
				ft_putchar('-');
			ret = flags_print(params, ft_nbsize(nb) + params->pos_nb + 1);
			if (params->flags != '0')
				ft_putchar('-');
		}
 		else if (nb >= 0)
			ret = flags_print(params, ft_nbsize(nb) + params->pos_nb);
	}
	ft_putnbr(nb);
	if (params->neg)
		ret = flags_print(params, ft_nbsize(nb) + params->pos_nb);
	if (ret == 0 && nb != 0)
		return (ft_nbsize(nb));
	return (ret);
}
