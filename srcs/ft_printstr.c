/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 19:10:59 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/30 19:33:14 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		ft_printchar(char c, t_params *params)
{
	int ret;

	ret = 0;
	if (!params->count_flags || !c || params->flags == 't')
	{
		ft_putchar(c);
		return (1);
	}
	if (!params->neg)
		ret = flags_print(params, 1);
	ft_putchar(c);
	if (params->neg)
		ret = flags_print(params, 1);
	return (ret);
}


int		ft_printwchar(wchar_t *wstr, t_params *params)
{
	int ret;

	ret = 0;
	if (params->count_flags == 0 || !wstr || params->flags == 't')
	{
		ft_putwstr(wstr);
		return (ft_lenghstrwchar(wstr));
	}
	if (!params->neg)
		ret = flags_print(params, ft_lenghstrwchar(wstr));
	ft_putwstr(wstr);
	if (params->neg)
		ret = flags_print(params, ft_lenghstrwchar(wstr));
	return (ret);
}

int		ft_printstr(char *str, t_params *params)
{
	int ret;

	ret = 0;
	if ((int)ft_strlen(str) > params->count_flags || !str || params->flags == 't')
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	if (!params->neg)
		ret = flags_print(params, ft_strlen(str));
	ft_putstr(str);
	if (params->neg)
		ret = flags_print(params, ft_strlen(str));
	return (ret);
}
