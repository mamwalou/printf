#include "Includes/libft.h"

void			ft_printunlong(unsigned long long ll)
{
	size_t	ret;

	ret = 1;
	if (ll >= 10)
	{
		ft_printunlong(ll / 10);
		ft_printunlong(ll % 10);
	}
	else
		ft_putchar(ll + '0');
}
