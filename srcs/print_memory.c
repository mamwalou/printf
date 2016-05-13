/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:20:50 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:20:54 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int 			printhex(size_t nb, char *base)
{
	static int count;

	count = 0;
	if (nb >= 16)
		printhex(nb / 16, base);
	ft_putchar(base[(int)(nb % 16)]);
	count++;
	return(count);
}

int			ft_print_memory(void *addr, size_t size)
{

	size_t ptr_to_print;
	int ret;

	(void)size;
	ret = 2;
	ptr_to_print = (size_t)addr;
	ft_putstr("0x");
	ret += printhex(ptr_to_print, "0123456789abcdef");
	return (ret);
}
