#include "../inc/my_printf.h"

int     low_convert(va_list ap, int pos)
{
    int d;
    char *s;
    if (pos == 12)
    {
        d = va_arg(ap, int);
        ft_putnbr(d);
    }
    if (pos == 0)
    {
        s = va_arg(ap, char *);
        ft_putstr(s);
    }
}
