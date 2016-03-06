#include "../inc/my_printf.h"

int     print_integer(t_params params, t_args *args, const char *format)
{

}
void    ft_printf(t_params params, t_args *args, const char *format)
{
    print_integer(params, args, format);
    print_floating(params, args, format);
    print_string(params, args, format);
}
