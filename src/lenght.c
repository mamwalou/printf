#include "../inc/my_printf.h"

int			str_check(const char *str)
{
	int i;

	i = 0;
	if (str[i] == 'h' && str[i + 1] == 'h')
		return (6);
	else if (str[i] == 'l' && str[i + 1] == 'l')
		return (7);
	return (0);
}

int 		lenght_gest(const char *str)
{
	char	tab[LENGHT];
	int		i;

	tab[0] = 't';
	tab[1] = 'h';
	tab[2] = 'l';
	tab[3] = 'L';
	tab[4] = 'j';
	tab[5] = 'z';
	if ((i = str_check(str)) > 0)
		return (i);
	else
	{
		while (i <= 5)
		{
			if (tab[i] == *str)
				return (i);
			i++;
		}
	}
	return (i);
}
