/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:20:50 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/11 17:14:50 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int			ft_print_memory(t_params *params, void *addr)
{
	size_t ptr_to_print;
	int ret;
	int tmp;

	tmp = 2;
	ptr_to_print = (size_t)addr;
	tmp += cthex(ptr_to_print, "0123456789abcdef");
	if (tmp > params->count_flags)
	{
		ft_putstr("0x");
		printhex(ptr_to_print, "0123456789abcdef");
		return (tmp);
	}
	if (params->flags == ' ' && params->count_flags && !params->neg)
		ret = flags_print(params, tmp);
	ft_putstr("0x");
	printhex(ptr_to_print, "0123456789abcdef");
	if ((params->flags == '0') || (params->flags == ' ' && params->neg))
		ret = flags_print(params, tmp);
	return (ret);
}
