#include "../includes/my_printf.h"

int        convert_uloctal(unsigned long long nb, int size_nb)
{
	char octal[size_nb];
    int tmp;
    int i;
	int count;

    i = 1;
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
    while (nb != 0)
    {
        tmp = nb % 8;
        octal[count++] = tmp + 48;
		nb /= 8;
    }
	ft_putstr_rev(octal, count);
	return(count);
}

int        convert_loctal(long long nb, int size_nb)
{
	char octal[size_nb];
    int tmp;
    int i;
	int count;

    i = 1;
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
    while (nb != 0)
    {
        tmp = nb % 8;
        octal[count++] = tmp + 48;
		nb /= 8;
    }
	ft_putstr_rev(octal, count);
	return(count);
}

int        convert_octal(unsigned int nb, int size_nb)
{
	char octal[size_nb];
    int tmp;
    int i;
	int count;

    i = 1;
	count = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
    while (nb != 0)
    {
        tmp = nb % 8;
        octal[count++] = tmp + 48;
		nb /= 8;
    }
	ft_putstr_rev(octal, count);
	return(count);
}

int    convert_unlhx(unsigned long long nb, int size_nb, int maj)
{
    char hex[size_nb];
	int tmp;
	int i;

	i = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
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
	ft_putstr_rev(hex, i);
	return (i);
}

int    convert_hx(unsigned int nb, int size_nb, int maj)
{
    char hex[size_nb];
	int tmp;
	int i;

	i = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
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
	ft_putstr_rev(hex, i);
	return (i);
}
