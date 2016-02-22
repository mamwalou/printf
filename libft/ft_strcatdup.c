
#include "Includes/libft.h"

char *ft_strcatdup(const char *s1, const char *s2)
{
	char *ret;
	char *tmp;
	char *tmp1;
	int i;
	int y;

	tmp = (char*)s1;
	tmp1 = (char*)s2;
	i = 0;
	y = 0;
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (tmp[i])
		ret[y++] = tmp[i++];
	i = 0;
	while(tmp1[i])
		ret[y++] = tmp1[i++];
	ret[y] = '\0';
	return (ret);
}
