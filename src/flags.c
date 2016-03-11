#include "../inc/my_printf.h"


int			specifier(char format)
{
	int tab[FORMAT];
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
	tab[12] = 'd';
	tab[13] = 'f';
	i = 0;
	while (i < FORMAT)
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

int 		lenght_gest(const char *str)
{
	char	*tab[LENGHT];
	int		i;

	tab[0] = "t";
	tab[1] = "h";
	tab[2] = "l";
	tab[3] = "L";
	tab[4] = "j";
	tab[5] = "z";
	tab[6] = "hh";
	tab[7] = "ll";
	i = 0;
	while (i <= LENGHT)
	{
		if (!ft_strcmp(tab[i], str))
			return (i);
		i++;
	}
	return (i);
}
