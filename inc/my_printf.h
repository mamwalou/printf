#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/Includes/libft.h"

# define UNCHAR unsigned char
# define UNINT unsigned int
# define UNSHORT unsigned short
# define SICHAR signed char
# define SIINT signed int
# define FORMAT 14

typedef struct				s_var
{
		char		*str;
		UNCHAR		unchr;
		UNINT		unint;
		UNSHORT		unshor;
		SIINT		sint;
		SICHAR		signchar;
}							t_var;

void 	printf_gest(va_list ap, int pos);
int	    low_convert(va_list ap, int pos);
void	gest_error(va_list ap, int pos);

#endif
