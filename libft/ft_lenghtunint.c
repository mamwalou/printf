#include "Includes/libft.h"

int			ft_lenghtunint(unsigned int nb)
{
	size_t	ret;

	ret = 1;
	if (nb == UINT_MAX)
		return (10);
	while ((nb /= 10) > 0)
		ret++;
	return (ret);
}
