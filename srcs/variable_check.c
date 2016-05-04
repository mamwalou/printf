#include "../includes/my_printf.h"

int     specifier_s(t_params *params, t_args *args, t_tabvar *var)
{
    if (params->lenght > LENGHT)
    {
        if ((var->var_str = va_arg(args->ap, char*)) != NULL)
			ft_putstr(var->var_str);
		else
			ft_putstr("(null)");
    }
    return(ft_strlen(var->var_str));
}

int     specifier_S(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght > LENGHT)
	{
		if ((var->var_wstr = va_arg(args->ap, wchar_t *)) != NULL)
		{
			ft_putwstr(var->var_wstr);
			return (ft_lenghstrwchar(var->var_wstr));

		}
		else
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	return (-1);
}

int     specifier_c(t_params *params, t_args *args, t_tabvar *var)
{
    if (params->lenght > LENGHT)
    {
        var->var_c = va_arg(args->ap, int);
        ft_putchar(var->var_c);
		return (1);
    }
    return (-1);
}

int specifier_C(t_params *params, t_args *args, t_tabvar *var)
{
	if (params->lenght > LENGHT)
	{
		if ((var->var_wint = va_arg(args->ap, wint_t)) != 0)
		{
			ft_putwchar(var->var_wint);
			return (ft_lenghtwchar(var->var_wint));
		}
		else
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	return (-1);
}
