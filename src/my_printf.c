#include "../inc/my_printf.h"
#include <stdio.h>
#define FORMAT 14

/*int			define_var(const char *format)
{
	int tab[FORMAT];
	int i;

	tab[0] = 's';
	tab[1] = 'S';
	tab[2] = 'c';
	tab[3] = 'C';
	tab[4] = 'D';
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
	while (tab[i])
	{
		if (format == tab[i])
			return(i);
		i++;
	}
	return (FORMAT);
}*/

void		init_parm(t_params *params)
{
	params->zero = NO;
	params->width = 0;
	params->space = 0;
	params->precision = 0;
	params->lenght = 0;
}
int			to_convert(t_args *args, const char *str, t_params *params)
{
	int i;

	i = 0;
	init_parm(params);
	if (str[i] == '%')
		i += 1;
	while ((flags(str, i, params)) > 0)
		i += 1;
	while ((init_width(str, i, params)) > 0)
		i += 1;
	if (str[i] == '.')
	{
		i += 1;
		while ((get_precision(str, i, params)) > 0)
			i += 1;
	}
	if (str[i])
		params->lenght = lenght_gest(str);
}

int			my_printf(const char *format, ...)
{
	int		i;
	int		pos;
	t_args	args;
	t_params params;

	i = 0;
	pos = 0;
	va_start(args.ap, format);
	while (format[i])
	{
		va_start(args.tmp_ap, format);
		if (format[i] == '%' && to_convert(&args, format + i, &params))
			;
		i++;
		va_end(args.tmp_ap);
	}
	va_end(args.ap);
	return(0);
}

int			main()
{
	my_printf("%42.1092");
	return (0);
}
