/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:57:28 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/26 20:35:25 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		flags_print(t_params *params, int ref)
{
	int diff;

	if (params->neg)
		ft_putchar('-');
	diff = params->count_flags - ref;
	while (diff--)
		ft_putchar(params->flags);
	return (params->count_flags);
}
