#include "Includes/libft.h"

void		ft_putstr_rev(char *s)
{
	int		size;

	size = ft_strlen(s);
	while (size-- > 0)
		ft_putchar(s[size]);
}
