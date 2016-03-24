#include "../includes/my_printf.h"

int			specifier(char format)
{
	int tab[SPECIFIER];
	int i;

	tab[0] = 's';
	tab[1] = 'S';
	tab[2] = 'c';
	tab[3] = 'C';
	tab[4] = 'd';
	tab[5] = 'i';
	tab[6] = 'o';
	tab[7] = 'O';
	tab[8] = 'u';
	tab[9] = 'U';
	tab[10] = 'x';
	tab[11] = 'X';
	tab[12] = 'f';
	i = 0;
	while (i < SPECIFIER)
	{
		if (format == tab[i])
			return(i);
		i++;
	}
	return (i);
}

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
