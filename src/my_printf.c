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
	params->width = NO;
	params->space = 0;
}
int			to_convert(t_args *args, const char *str, t_params *params)
{
	int i;

	i = 0;
	init_parm(params);
	if (str[i] == '%')
		i += 1;
	while ((flags(str, i, params)) > 1)
		i += 1;
	while ((init_width(str, i, params)) > 1)
		i += 1;
	if (str[i] == '.')
		params->precision = get_precision(str, i);
	ft_putchar(str[i]);
	exit (1);
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

	//my_printf("%*d", 10);
	printf("%+.*s\n", "test");
	return (0);
}
