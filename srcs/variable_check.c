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
	int		count;

	count = 0;
	(void)params;
    str = va_arg(args->ap, wchar_t *);
	count = ft_lenghstrwchar(str);
    ft_putwstr(str);
    return (count);
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
	int		count;

	if (params->lenght > LENGHT)
	{
		count = 0;
		test = va_arg(args->ap, wchar_t);
		count = ft_lenghtwchar(test);
		ft_putwchar(test);
	}
    return (count);
}
