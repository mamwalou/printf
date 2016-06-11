/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 15:44:22 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/11 16:25:38 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		space_print(t_params *params, int nb)
{
	int is_neg;
	int ret;

	ret = 0;
	is_neg = 0;
	if ((!params->neg) && (nb > 0 || params->flags != 't'))
	{
		if (nb < 0 && params->flags == '0')
		{
			nb = -nb;
			is_neg++;
			ft_putchar('-');
		}
		ret = flags_print(params, ft_nbsize(nb) + is_neg);
	}
	ft_putnbr(nb);
	if (params->neg)
		ret = flags_print(params, ft_nbsize(nb) + is_neg);
	if (ret == 0 && nb != 0)
		return (ft_nbsize(nb));
	return (ret);
}
