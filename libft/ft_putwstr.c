#include "Includes/libft.h"

void 	ft_putwstr(wchar_t *s)
{
	while (*s)
		ft_putwchar_fd(*s++, 1);
}
