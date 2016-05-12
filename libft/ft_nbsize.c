#include "Includes/libft.h"

size_t		ft_nbsize(int nb)
{
	size_t	ret;

	ret = 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		ret++;
		nb *= -1;
	}
	while ((nb /= 10) > 0)
		ret++;
	return (ret);
}
