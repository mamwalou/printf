
#include "../inc/my_printf.h"
#include <stdio.h>

int			define_var(int format)
{
	int tab[FORMAT];
	int cnt;

	cnt = 0;
	tab[0] = 's';
	tab[1] = 'S';
	tab[2] = 'c';
	tab[3] = 'C';
	tab[4] = 'D';
	tab[5] = 'i';
	tab[6] = 'o';
	tab[7] = 'O';
	tab[8] = 'u';
	tab[9] = 'U';
	tab[10] = 'x';
	tab[11] = 'X';
	tab[12] = 'p';
	tab[13] = 'd';
	while (cnt < FORMAT)
	{
		if (format == tab[cnt])
			return(cnt);
		cnt++;
	}
	return (cnt);
}
int			my_printf(const char *format, ...)

{
	va_list		ap;
	int			*tab;
	int			pos;

	pos = 0;
	va_start(ap, format);
	tab = ft_memalloc((size_t)FORMAT - 1);
	while (*format)
	{
		if ((*format++) == '%')
			if ((pos = define_var(*format)) < FORMAT)
			low_convert(ap, pos);
		ft_putchar(*format);
	}
	va_end(ap);
	return(0);
}

int			main()
{

	my_printf("%uqwdqwd%c %s", 42, 'c', "test");
	return (0);
}
