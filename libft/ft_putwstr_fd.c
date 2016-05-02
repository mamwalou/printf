#include "Includes/libft.h"

void 	ft_putwstr_fd(wchar_t *s, int fd)
{
	while (*s)
		ft_putwchar_fd(*s++, fd);
}
