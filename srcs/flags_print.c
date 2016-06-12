/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:57:28 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/12 21:42:27 by sbeline          ###   ########.fr       */
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

int				sharp_printhx(int nb, int maj, int tmp)
{
	if (nb > 0)
	{
		if (!maj)
		{
			ft_putstr("0x");
			printhex(nb, "0123456789abcdef");
		}
		else
		{
			ft_putstr("0X");
			printhex(nb, "0123456789ABCDEF");
		}
		return (tmp + 2);
	}
	ft_putchar('0');
	return (1);
}

int				sharp_printoc(int nb, int tmp)
{
	ft_putchar('0');
	if (nb > 0)
	{
		printoctal(nb, "012345678");
		return (tmp + 1);
	}
	return (1);
}
