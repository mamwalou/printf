/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:56:17 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/18 15:56:21 by sbeline          ###   ########.fr       */
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

int		space_printoc(t_params *params, int tmp, int nb)
{
	int ret;

	ret = 0;
	if (!params->neg)
		ret = flags_print(params, tmp);
	printoctal(nb, "012345678");
	if (params->neg)
		ret = flags_print(params, tmp);
	return (0);
}

int		space_printhx(t_params *params, int tmp, int nb, int maj)
{
	int ret;

	ret = 0;
	if (!params->neg)
		ret = flags_print(params, tmp);
	if (!maj)
		printhex(nb, "0123456789abcdef");
	else
		printhex(nb, "0123456789ABCDEF");
	if (params->neg)
		ret = flags_print(params, tmp);
	return (ret);
}
