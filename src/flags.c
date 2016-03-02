#include "../inc/my_printf.h"

int			flags(const char *str, int pos, t_params *params)
{
	if (str[pos] == '0' || str[pos] == '+' || str[pos] == ' ')
		return (1);
	return (0);
}

int			init_width(const char *str, int pos, t_params *params)
{
	if (str[pos] == '*' || ft_isdigit(str[pos] > 0))
		return (1);
	return (0);
}

int			get_precision(const char *str, int pos)
{
	int ret;
	int i;

	ret = 0;
	if (str[pos] == '*')
		return (1);
	while (ft_isdigit(str[pos]) > 0)
		i++;
}
