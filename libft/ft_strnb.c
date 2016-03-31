#include "Includes/libft.h"

int					ft_strnb(void *var)
{
	int				size;
	int				nb;

	size = 1;
	nb = *(int*)var;
	while (nb >= 10)
	{
		nb = nb / 10;
		size = size + 1;
	}
	return (size);
}
