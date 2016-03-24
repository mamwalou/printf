#include "../includes/my_printf.h"

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

void    convert_hexlow(unsigned int nb)
{
    char tab[8] = {'a','b','c','d','e','f','g'};
    int tmp;
    int tmp2;
    int i;
    char tmp3;

    while (nb / 16 > 0)
    {
        tmp = nb % 16;
        nb /= 16;
        tmp2 += tmp * i;
        if (tmp2 > 9)
            tmp3 = tab[tmp2 - 10];
        i *= 10;
    }

}
