/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline  <sbeline @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:09:02 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/26 20:38:04 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

int		printnbr(int nb, t_params *params)
{
	int ret;
	int is_neg;

	ret = 0;
	if (nb < 0)
	{
		is_neg = 1;
	}
	if ((int)ft_nbsize(nb) > params->count_flags)
	{
		ft_putnbr(nb);
		return (ft_nbsize(nb));
	}
	if (!params->neg)
		ret = flags_print(params, ft_nbsize(nb));
	ft_putnbr(nb);
	if (params->neg)
		ret = flags_print(params, ft_nbsize(nb));
	return (ret);
}

int		ft_printchar(char c, t_params *params)
{
	int ret;

	ret = 0;
	if (!params->count_flags)
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
	if (ft_lenghstrwchar(wstr) > params->count_flags)
	{
		ft_putwstr(wstr);
		return (ft_lenghstrwchar(wstr));
	}
	if (!params->neg)
		ret = flags_print(params,ft_lenghstrwchar(wstr));
	ft_putwstr(wstr);
	if (params->neg)
		ret = flags_print(params, ft_lenghstrwchar(wstr));
	return (ret);
}
