#include "../includes/my_printf.h"

void 			printhex(size_t nb, char *base)
{
	if (nb >= 16)
		printhex(nb / 16, base);
	ft_putchar(base[(int)(nb % 16)]);
}

int			ft_print_memory(void *addr, size_t size)
{

	size_t ptr_to_print;
	int ret;

	(void)size;
	ret = 3;
	ptr_to_print = (size_t)addr;
	ft_putstr("0x");
	printhex(ptr_to_print, "0123456789abcdef");
	ret += ft_nbsize((int)ptr_to_print);
	return (ret);
}
