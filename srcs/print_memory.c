/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:20:50 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/23 19:32:03 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static void 			printhex(size_t nb, char *base)
{
	if (nb >= 16)
		printhex(nb / 16, base);
	ft_putchar(base[(int)(nb % 16)]);
}

static int 			cthex(size_t nb, char *base)
{
	static int count;

	count = 0;
	if (nb >= 16)
		cthex(nb / 16, base);
	count++;
	return(count);
}

int			ft_print_memory(t_params *params, void *addr)
{
	size_t ptr_to_print;
	int ret;
	int count;

	ret = 2;
	ptr_to_print = (size_t)addr;
	ret += cthex(ptr_to_print, "0123456789abcdef");
	if (params->count_flags > 0)
	{
		count = params->count_flags - ret;
		if (count < 0)
		{
			printhex(ptr_to_print, "0123456789abcdef");
			return (ret);
		}
		while (count--)
			ft_putchar(' ');
		ft_putstr("0x");
		printhex(ptr_to_print, "0123456789abcdef");
		return (params->count_flags);
	}
	ft_putstr("0x");
	printhex(ptr_to_print, "0123456789abcdef");
	if (params->count_flags < 0)
	{
		params->count_flags = -params->count_flags;
		count = params->count_flags - ret;
		if (count < 0)
			return (ret);
		while (count-- != 0)
			ft_putchar(' ');
		return(params->count_flags);
	}
	return (ret);
}
