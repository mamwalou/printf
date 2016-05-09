#include "../includes/my_printf.h"


static void		init_parm(t_params *params)
{
	params->width = 0;
	params->precision = 0;
	params->lenght = 0;
	params->specifier = 0;
}

static void 	init_var(t_tabvar *var)
{
	var->var_wstr = NULL;
	var->var_wint = 0;
	var->var_c = 0;
	var->var_str = 0;
	var->var_int = 0;
	var->var_longlong = 0;
	var->var_unsint = 0;
	var->var_unlonglong = 0;
	var->var_double = 0;
}
int			to_convert(const char *str, int *pos, t_params *params)
{
	if (str[*pos] != '%')
		return (-1);
	*pos += 1;
	if (str[*pos] == '%')
		return (-1);
	while ((flags(str, *pos, params)) > 0)
		*pos += 1;
	while ((init_width(str, *pos, params)) > 0)
		*pos += 1;
	if (str[*pos] == '.')
	{
		*pos += 1;
		while ((get_precision(str, *pos, params)) > 0)
			*pos += 1;
	}
	params->lenght = lenght_gest(str + *pos);
	if (params->lenght < 6)
		*pos += 1;
	if (params->lenght == 6 || params->lenght == 7)
		*pos += 2;
	if ((params->specifier = specifier(str[*pos])) < SPECIFIER)
		*pos += 1;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			ret;
	t_args		args;
	t_tabvar	var;
	t_params	params;

	i = 0;
	ret = 0;
	va_start(args.ap, format);
	init_parm(&params);
	init_var(&var);
	while (format[i])
	{
		if ((to_convert(format, &i, &params)) > 0)
			ret += my_printf(&params, &args, &var);
		else
		{
			ft_putchar(format[i]);
			i++;
			ret++;
		}
	}
	va_end(args.ap);
	return(ret);
}
