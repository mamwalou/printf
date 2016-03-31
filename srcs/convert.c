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

void    convert_hexlow(unsigned int nb, int size_nb, int maj)
{
    char hex[size_nb + 1];
	int tmp;
	int i;

	i = 0;
	while (nb != 0)
	{
		tmp = nb % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
		{
			if (maj)
				tmp = tmp + 55;
			else
				tmp = tmp + 87;
		}
		hex[i++] = tmp;
		nb = nb / 16;
	}
	ft_putstr_rev(hex);
}
