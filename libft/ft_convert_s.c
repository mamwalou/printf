/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:28:48 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 16:28:50 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_convert_s(char **s)
{
	int i = 1;
	int j = 0;
	int h = 0;
	char *ret;

	if (s[i] == NULL)
		return(NULL);
	ret = ft_strnew(ft_lenght_array(s) + 1);
	while (s[i])
	{
		j = 0;
		while(s[i][j])
		ret[h++] = s[i][j++];
		i++;
	}
	return(ret);
}
