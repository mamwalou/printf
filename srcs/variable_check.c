#include "../includes/my_printf.h"

int     specifier_s(t_params *params, t_args *args)
{
    char *s;

    if (params->lenght > LENGHT)
    {
        s = va_arg(args->ap, char*);
        ft_putstr(s);
    }
    return(ft_strlen(s));
}

int     specifier_S(t_params *params, t_args *args)
{
    wchar_t *str;

	(void)params;
    str = (wchar_t*)va_arg(args->ap, char *);
    ft_putstr((char*)str);
    return (0);
}

int     specifier_c(t_params *params, t_args *args)
{
    char c;


    if (params->lenght > LENGHT)
    {
        c = va_arg(args->ap, int);
        ft_putchar(c);
    }
    return (0);
}

int specifier_C(t_params *params, t_args *args)
{
    wchar_t test;

	(void)params;
	if (params->lenght > LENGHT)
	{
		test = va_arg(args->ap, wchar_t);
		ft_putchar((const char)unicode_to_utf8(test));
	}
    return (0);
}
