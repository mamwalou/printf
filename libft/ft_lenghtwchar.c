#include "Includes/libft.h"

int		ft_lenghtwchar(wchar_t wc)
{
	if (wc < (1 << 7))
		return (1);
	else if (wc < (1 << 11))
		return (2);
	else if (wc < (1 << 16))
		return (3);
	else if (wc < (1 << 21))
		return (4);
	return (-1);
}
