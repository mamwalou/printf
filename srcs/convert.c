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

unsigned char* unicode_to_utf8(wchar_t c)
{
    static unsigned char b_static[5];
    unsigned char* b = b_static;

    if (c<(1<<7))// 7 bit Unicode encoded as plain ascii
    {
        *b++ = (unsigned char)(c);
    }
    else if (c<(1<<11))// 11 bit Unicode encoded in 2 UTF-8 bytes
    {
        *b++ = (unsigned char)((c>>6)|0xC0);
        *b++ = (unsigned char)((c&0x3F)|0x80);
    }
    else if (c<(1<<16))// 16 bit Unicode encoded in 3 UTF-8 bytes
        {
        *b++ = (unsigned char)(((c>>12))|0xE0);
        *b++ =  (unsigned char)(((c>>6)&0x3F)|0x80);
        *b++ =  (unsigned char)((c&0x3F)|0x80);
    }

    else if (c<(1<<21))// 21 bit Unicode encoded in 4 UTF-8 bytes
    {
        *b++ = (unsigned char)(((c>>18))|0xF0);
        *b++ = (unsigned char)(((c>>12)&0x3F)|0x80);
        *b++ = (unsigned char)(((c>>6)&0x3F)|0x80);
        *b++ = (unsigned char)((c&0x3F)|0x80);
    }
    *b = '\0';
    return (b_static);
}
