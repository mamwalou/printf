/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:29:20 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:29:24 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int			ft_lenghtlong(long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll == LONG_LONG_MIN)
		return (20);
	if (ll < 0)
	{
		ret++;
		ll *= -1;
	}
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}
