/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:55:38 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/23 17:24:50 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static int		flags_print1(t_params *params, int ref, int cnt)
{
	int			cnt2;
	int			diff;

	cnt2 = 0;
	diff = 0;
	if (cnt > params->count_flags - ref)
	{
		cnt2 = cnt - params->count_flags - ref;
		diff = cnt2;
	}
	else
	{
		cnt2 = params->count_flags - ref - cnt;
		diff = cnt2;
	}
	while (diff--)
	{
		if (params->neg)
			ft_putchar(' ');
		else
			ft_putchar(params->flags);
	}
	return (cnt2 + cnt + ref);
}

int				flags_print(t_params *params, int ref)
{
	int			cnt;

	cnt = 0;
	if (params->tflags == 't')
	{
		cnt = params->count_tflags;
		while (params->count_tflags-- && !params->neg)
			ft_putchar(' ');
	}
	if (!params->count_flags)
		return (cnt + ref);
	return (flags_print1(params, ref, cnt));
}

static int				sharp_printhx1(int nb, int maj, int tmp, t_params *p)
{
	if (!maj)
	{
		if (p->flags == '0' || p->flags == ' ')
			return (space_printhx(p, tmp + 2, nb, maj));
		else
		{
			ft_putstr("0x");
			printhex(nb, "0123456789abcdef");
			return (tmp + 2);
		}
	}
	else
	{
		if (p->flags == '0' || p->flags == ' ')
			return (space_printhx(p, tmp + 2, nb, maj));
		else
		{
			ft_putstr("0X");
			printhex(nb, "0123456789ABCDEF");
			return (tmp + 2);
		}
	}
	return (tmp + 2);
}

int				sharp_printhx(int nb, int maj, int tmp, t_params *p)
{
	if (nb == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	if (tmp < p->count_flags)
		return (sharp_printhx1(nb, maj, tmp, p));
	else
	{
		if (!maj)
		{
			ft_putstr("0x");
			printhex(nb, "0123456789abcdef");
			return (tmp + 2);
		}
		else
		{
			ft_putstr("0X");
			printhex(nb, "0123456789ABCDEF");
			return(tmp + 2);
		}

	}
	return (1);
}

int				sharp_printoc(int nb, int tmp, t_params *params)
{
	if (tmp > params->count_flags)
	{
		if (nb == 0)
		{
			ft_putnbr(0);
			return (1);
		}
		ft_putnbr(0);
		printoctal(nb, "012345678");
		return (tmp);
	}
	if (params->flags == '0' || params->flags == ' ')
		return (space_printoc(params, tmp, nb));
	return (tmp);
}
