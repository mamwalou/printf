/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 21:41:01 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/21 16:58:19 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

void			printoctal(size_t nb, char *base)
{
	if (nb >= 8)
		printoctal(nb / 8, base);
	ft_putchar(base[(int)(nb % 8)]);
}

int				ctoctal(size_t nb, char *base)
{
	static int count;

	count = 0;
	if (nb >= 8)
		ctoctal(nb / 8, base);
	count++;
	return (count);
}

int				con_uloctal(unsigned long long nb, t_params *params)
{
	int			ret;
	int			tmp;

	tmp = 0;
	ret = 0;
	tmp += ctoctal(nb, "012345678");
	if (params->sharp)
		return (sharp_printoc(nb, tmp + 1, params));
	if (nb == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	if (tmp >= params->count_flags)
	{
		printoctal(nb, "012345678");
		return (tmp);
	}
	if (params->flags == '0' || params->flags == ' ')
		return (space_printoc(params, tmp, nb));
	return (ret);
}

int				con_loctal(long long nb, t_params *params)
{
	int			ret;
	int			tmp;

	tmp = 0;
	ret = 0;
	tmp += ctoctal(nb, "012345678");
	if (params->sharp)
		return (sharp_printoc(nb, tmp + 1, params));
	if (nb == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	if (tmp >= params->count_flags)
	{
		printoctal(nb, "012345678");
		return (tmp);
	}
	if (params->flags == '0' || params->flags == ' ')
		return (space_printoc(params, tmp, nb));
	return (ret);
}

int				con_octal(unsigned int nb, t_params *params)
{
	int			ret;
	int			tmp;

	tmp = 0;
	ret = 0;
	tmp += ctoctal(nb, "012345678");
	if (params->sharp)
		return (sharp_printoc(nb, tmp + 1, params));
	if (nb == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	if (tmp >= params->count_flags)
	{
		printoctal(nb, "012345678");
		return (tmp);
	}
	if (params->flags == '0' || params->flags == ' ')
		return (space_printoc(params, tmp, nb));
	return (ret);
}
