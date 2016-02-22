#include "Includes/libft.h"

int		ft_findstr(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 == *s2)
			s1++;
		if (*s1 == '\0')
			return (1);
		s2++;
	}
	return(0);
}
