#include "Includes/libft.h"

int		ft_strcmp_date(time_t t1, time_t t2, int reverse)
{
	if (reverse)
	{
		if (t1 < t2)
			return (-1);
		if (t1 > t2)
			return (1);
		return(0);
	}
	if (t1 < t2)
		return (1);
	if (t1 > t2)
		return (-1);
	return(0);
}
