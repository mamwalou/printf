#include "Includes/libft.h"

int		ft_lenghstrwchar(const wchar_t *wc)
{
	int count;

	count = 0;
	while (*wc)
		count += ft_lenghtwchar(*wc++);
	return (count);
}
