#include "../inc/my_printf.h"

int			flags(const char *str, int pos, t_params *params)
{
	if (str[pos] == '0' || str[pos] == '+' || str[pos] == ' ')
	{
		params->flags = str[pos];
		return (1);
	}
	return (0);
}

int			init_width(const char *str, int pos, t_params *params)
{
	int		tmp;

	if (str[pos] == '*')
		return (0);
	if (ft_isdigit(str[pos]) > 0)
	{
		tmp = str[pos] - 48;
		if (params->width != 0)
			params->width = tmp + params->width * 10;
		else
			params->width = tmp;
		return (1);
	}
	return (0);
}

int			get_precision(const char *str, int pos, t_params *params)
{
	int		tmp;

	if (str[pos] == '*')
		return (0);
	if (ft_isdigit(str[pos]) > 0)
	{
		tmp = str[pos] - 48;
		if (params->precision != 0)
			params->precision = tmp + params->precision * 10;
		else
			params->precision = tmp;
		return (1);
	}
	return (0);
}

int 		lenght_gest(const char *str, t_params *params)
{
	char	*tab[LENGHT];
	int		i;

	tab[0] = "hh";
	tab[1] = "h";
	tab[2] = "l";
	tab[3] = "ll";
	tab[4] = "j";
	tab[5] = "z";
	tab[6] = "t";
	tab[7] = "L";
	i = 0;
	while (ft_strcmp(tab[i], str) != 0)
			i++;
	return (i);
}
