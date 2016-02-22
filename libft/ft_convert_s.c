#include "Includes/libft.h"
char	*ft_convert_s(char **s)
{
	int i = 1;
	int j = 0;
	int h = 0;
	char *ret;

	if (s[i] == NULL)
		return(NULL);
	ret = ft_strnew(ft_lenght_array(s) + 1);
	while (s[i])
	{
		j = 0;
		while(s[i][j])
		ret[h++] = s[i][j++];
		i++;
	}
	return(ret);

}
