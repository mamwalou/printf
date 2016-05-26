/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 15:57:28 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/26 19:23:17 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		flags_print(t_params *params, int ref)
{
	int diff;

	diff = params->count_flags - ref;
	while (diff--)
		ft_putchar(params->flags);
	return (params->count_flags);
}
