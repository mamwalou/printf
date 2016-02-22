#include "Includes/libft.h"

char	*strconct(char *s1, char *s2, const char *obj)
{
	char *tmp;
	char *ret;

	tmp = ft_strcatdup(s1, obj);
	ret = ft_strcatdup(tmp, s2);
	return (ret);
}
