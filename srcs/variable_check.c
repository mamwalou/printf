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
    wint_t win;

	(void)params;
    win = (wint_t)va_arg(args->ap, int);
    ft_putchar((char)win);
    return (0);
}
