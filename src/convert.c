#include "../inc/my_printf.h"

void       convert_hexlow(unsigned int nb)
{
    return ;
}

void        convert_octal(unsigned int nb)
{
    int tmp;
    int octal;
    int i;

    i = 1;
    octal = 0;
    while (nb != 0)
    {
        tmp = nb % 8;
        nb /= 8;
        octal += tmp * i;
        i *= 10;
    }
    ft_putnbr(octal);
}
