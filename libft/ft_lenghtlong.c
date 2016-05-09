#include "Includes/libft.h"

int			ft_lenghtlong(long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll == LONG_LONG_MIN)
		return (20);
	if (ll < 0)
	{
		ret++;
		ll *= -1;
	}
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}
