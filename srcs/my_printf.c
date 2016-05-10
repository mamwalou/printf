#include "../includes/my_printf.h"


static void		init_parm(t_params *params)
{
	params->width = 0;
	params->precision = 0;
	params->lenght = 0;
	params->specifier = 0;
	params->count_flags = 0;
	params->flags = 0;

}

int			to_convert(const char *str, int *pos, t_params *params)
{
	int count_space;

	init_parm(params);
	count_space = 0;
	if (str[*pos] != '%')
		return (-1);
	*pos += 1;
	while (str[*pos])
	{
		if ((flags(str, pos, params)) > 0)
			;
		while ((init_width(str, *pos + params->count_flags, params)) > 0)
			return (1);
		if (str[*pos] == '.')
		{
			*pos += 1;
			while ((get_precision(str, *pos, params)) > 0)
			{
				*pos += 1;
				return (count_space +1);
			}
		}
		params->lenght = lenght_gest(str + *pos + params->count_flags);
		if (params->lenght < 6)
			*pos += 1 + params->count_flags;
		if (params->lenght == 6 || params->lenght == 7)
			*pos += 2 + params->count_flags;
		if ((params->specifier = specifier(str[*pos + params->count_flags])) < SPECIFIER)
			*pos += 1 + params->count_flags;
		else
			return (-1);
		return (1);
	}
	return(-1);
}

int 		print(const char *format, int *pos ,t_params *params)
{
	if (params->count_flags)
		*pos += params->count_flags;
	if (format[*pos])
		ft_putchar(format[*pos]);
	else
		return(0);
	*pos += 1;
	return (1);

}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			ret;
	t_args		args;
	t_params	params;

	i = 0;
	ret = 0;
	va_start(args.ap, format);

	while (format[i])
	{
		if ((to_convert(format, &i, &params)) > 0)
			ret += my_printf(&params, &args);
		else
			ret += print(format, &i, &params);
	}
	va_end(args.ap);
	return(ret);
}
