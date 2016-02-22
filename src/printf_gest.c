# include "../inc/my_printf.h"

void    printf_gest(va_list ap, int pos)
{
    if ((low_convert(ap, pos)) == -1)
        gest_error(ap, pos);
}
