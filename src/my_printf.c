#include "../inc/my_printf.h"
#include <stdio.h>

static void		init_parm(t_params *params)
{
	params->width = 0;
	params->precision = 0;
	params->lenght = 0;
	params->specifier = 0;
}

int			to_convert(t_args *args, const char *str, t_params *params)
{
	int i;

	i = 0;
	if (str[i] == '%')
		i += 1;
	if (str[i] == '%')
		return (0);
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
	if ((params->lenght = lenght_gest(str) < 8))
		i += 1;
	params->specifier = specifier(str[i]);
	return (1);
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
	init_parm(&params);
	while (format[i])
	{
		va_start(args.tmp_ap, format);
		if (format[i] == '%' && to_convert(&args, format + i, &params) == 1)
		{
			ft_printf(params, &args);
			i += 1;
		}
		else
			ft_putchar(format[i]);
		i++;
		va_end(args.tmp_ap);
	}
	va_end(args.ap);
	return(0);
}

int			main()
{
	my_printf("%o\n", 774333);
	return (0);
}
