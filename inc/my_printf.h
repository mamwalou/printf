#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/Includes/libft.h"

# define HH 1
# define H 2
# define LL 3
# define L 4
# define J 5
# define Z 6
# define T 7

# define YES 1
# define NO 0

typedef struct			s_args
{
	va_list				ap;
	va_list				tmp_ap;
}						t_args;

typedef struct			s_params
{
	int					space;
	int					zero;
	int					width;
	int					precision;
}						t_params;

typedef struct			s_var
{
	unsigned char		unchar;
	unsigned int		unint;
	signed int			sigint;
	signed char			sigchar;
	short int			shortint;
	long int			longint;
	unsigned long int	unlongint;
	unsigned short int	unshorint;
}						t_var;

void 	printf_gest(va_list ap, int pos);
int     low_convert(va_list ap, int pos);
void	gest_error(va_list ap, int pos);

int 	flags(const char *str, int pos, t_params *params);
int		init_width(const char *str, int pos, t_params *params);
int		get_precision(const char *str, int pos, t_params *params);
#endif
