#include "Includes/libft.h"

size_t		ft_nbsize(int nb)
{
	int count;

	count = 1;
	if (nb > 0)
	{
		while ((nb /= 10) > 0)
			count++;
	}
	else
	{
		count += 1;
		while ((nb /= 10) < 0)
			count++;
	}
	return (count);
}
