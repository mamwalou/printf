/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-roux <cle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 23:43:09 by cle-roux          #+#    #+#             */
/*   Updated: 2016/06/20 18:21:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_strmove(char **s, int pos)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*s) - pos + 1);
	ft_strdel(s);
	*s = tmp;
}
