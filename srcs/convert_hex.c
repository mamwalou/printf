/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 21:40:04 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/23 17:24:17 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

void			printhex(size_t nb, char *base)
{
	if (nb >= 16)
		printhex(nb / 16, base);
	ft_putchar(base[(int)(nb % 16)]);
}

int				cthex(size_t nb, char *base)
{
	static int count;

	count = 0;
	if (nb >= 16)
		cthex(nb / 16, base);
	count++;
	return (count);
}

int				con_unlhx(unsigned long long nb, int maj, t_params *p)
{
	int			ret;
	int			tmp;

	tmp = 0;
	ret = 0;
	tmp += cthex(nb, "0123456789abcdef");
	if (p->sharp)
		return (sharp_printhx(nb, maj, tmp, p));
	if (tmp > p->count_flags)
	{
		if (!maj)
			printhex(nb, "0123456789abcdef");
		else
			printhex(nb, "0123456789ABCDEF");
		return (tmp);
	}
	if (p->flags == '0' || p->flags == ' ')
		return (space_printhx(p, tmp, nb, maj));
	return (ret);
}

int				con_hx(unsigned int nb, int maj, t_params *params)
{
	int			ret;
	int			tmp;

	tmp = 0;
	ret = 0;
	tmp += cthex(nb, "0123456789abcdef");
	if (params->sharp)
		return (sharp_printhx(nb, maj, tmp, params));
	if (tmp > params->count_flags)
	{
		if (!maj)
			printhex(nb, "0123456789abcdef");
		else
			printhex(nb, "0123456789ABCDEF");
		return (tmp);
	}
	if (params->flags == '0' || params->flags == ' ')
		return (space_printhx(params, tmp, nb, maj));
	return (ret);
}
