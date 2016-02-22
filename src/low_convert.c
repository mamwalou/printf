#include "../inc/my_printf.h"

static void print_char(va_list ap, int pos, t_var var)
{
    if (pos == 0)
    {
        var.str = va_arg(ap, char *);
        ft_putstr(var.str);
    }
    if (pos == 2)
    {
        var.unint = va_arg(ap, UNINT);
        ft_putchar(var.unint);
    }
}

static void print_int(va_list ap, int pos, t_var var)
{
    if (pos == 13 || pos == 5)
    {
        var.sint = va_arg(ap, SIINT);
        ft_putnbr(var.sint);
    }
    else if (pos == 8)
    {
        var.unint = va_arg(ap, UNINT);
        ft_putnbr(var.unint);
    }
}

static void init_var(t_var var)
{
    var.str = NULL;
    var.unchr = 0;
    var.unint = 0;
    var.unshor = 0;
    var.sint = 0;
    var.signchar = 0;
}
int     low_convert(va_list ap, int pos)
{
    t_var   var;

    init_var(var);
    if (pos >= 0 && pos <= 3)
        print_char(ap, pos, var);
    if (pos >= 4 && pos < FORMAT)
        print_int(ap, pos, var);
    return (1);
}
