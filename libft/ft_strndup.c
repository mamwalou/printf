#include "Includes/libft.h"

char	*ft_strndup(char *s, int begin, int end)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret  = (char*)malloc(sizeof(char) * (end - begin) + 1)))
		return(NULL);
	while (begin <= end)
	{
		ret[i] = s[begin];
		i++;
		begin++;
	}
	ret[i] = '\0';
	return (ret);
}
