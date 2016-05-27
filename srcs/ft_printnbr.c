/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:09:02 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/27 19:18:30 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		printnbr(int nb, t_params *params)
{
	int ret;
	int is_neg;

	ret = 0;
	is_neg = 0;
	if ((int)ft_nbsize(nb) > params->count_flags)
	{
		ft_putnbr(nb);
		return (ft_nbsize(nb));
	}
	if (!params->neg)
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
	return (ret);
}
