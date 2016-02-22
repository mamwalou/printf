/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:13:07 by sbeline           #+#    #+#             */
/*   Updated: 2015/07/22 14:28:03 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	index = 0;
	if ((str = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	while (index <= size)
	{
		str[index] = '\0';
		index++;
	}
	return (str);
}
