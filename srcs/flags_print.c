/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:57:28 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/30 17:03:10 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		flags_print(t_params *params, int ref)
{
	int diff;

	diff = 0;
	if (params->flags == 't')
	{
		diff = params->count_flags;
		while (params->count_flags--)
			ft_putchar(' ');
		return (diff + ref);
	}
	diff = params->count_flags - ref;
	while (diff--)
		ft_putchar(params->flags);
	return (params->count_flags);
}

int		sharp_printhx(int nb, int maj, int tmp)
{
	if (nb > 0)
	{
		ft_putstr("0x");
		if (!maj)
			printhex(nb, "0123456789abcdef");
		else
			printhex(nb, "0123456789ABCDEF");
		return (tmp + 2);
	}
	ft_putchar('0');
	return (1);
}

int		sharp_printoc(int nb, int tmp)
{
	ft_putchar('0');
	if (nb > 0)
	{
		printoctal(nb, "012345678");
		return (tmp + 1);
	}
	return (1);
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
