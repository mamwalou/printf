/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 10:16:07 by sbeline           #+#    #+#             */
/*   Updated: 2015/02/11 15:49:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static char		*ft_realloc(char *dest, char *source, size_t len)
{
	char		*cpy;

	cpy = ft_strnew(ft_strlen(dest) + len);
	cpy = ft_strcpy(cpy, dest);
	cpy = ft_strncat(cpy, source, len);
	free(dest);
	return (cpy);
}

void			new_line(char **buff, char ***line)
{
	*buff = ft_strnew(BUF_SIZE);
	**line = ft_strnew(0);
}

static int		get_line(char **line, char **buff, char *ptr_end, size_t len)
{
	char		*str;

	*line = ft_realloc(*line, *buff, len);
	str = ft_strnew(BUF_SIZE);
	str = ft_strcpy(str, ptr_end + 1);
	free(*buff);
	*buff = str;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char *buff = NULL;
	int			nb_read;
	char		*ptr;

	if (buff)
	{
		*line = ft_strnew(0);
		if ((ptr = ft_strchr(buff, '\n')))
			return (get_line(line, &buff, ptr, ptr - buff));
		*line = ft_realloc(*line, buff, ft_strlen(buff));
	}
	else
		new_line(&buff, &line);
	while ((nb_read = read(fd, buff, BUF_SIZE)) > 0)
	{
		buff[nb_read] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
			return (get_line(line, &buff, ptr, ptr - buff));
		*line = ft_realloc(*line, buff, nb_read);
	}
	return (nb_read);
}
