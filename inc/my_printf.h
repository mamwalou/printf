#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include "../libft/Includes/libft.h"
# include <stdio.h>

# define FORMAT 14
# define LENGHT 8


typedef struct			s_args
{
	va_list				ap;
	va_list				tmp_ap;
}						t_args;

typedef struct			s_params
{
	int					width;
	int					precision;
	int					flags;
	int					lenght;
	int					specifier;
	void 				*var;
}						t_params;

typedef struct			s_tab
{
	int					i;
	int 				(*f)(t_params *, t_args *);
}						t_tab;

					/*PRINT*/
void 	printf_gest(va_list ap, int pos);
void	gest_error(va_list ap, int pos);
void    ft_printf(t_params params, t_args *args);

					/*PARSING */
int 	flags(const char *str, int pos, t_params *params);
int		init_width(const char *str, int pos, t_params *params);
int		get_precision(const char *str, int pos, t_params *params);
int 	lenght_gest(const char *str);
int		specifier(char format);

					/*VARIABLE*/
void   varibale_define(t_params *params, t_args *args);
int    len_t(t_params *params, t_args *args);
int    len_h(t_params *params, t_args *args);
int    len_l(t_params *params, t_args *args);
int    len_L(t_params *params, t_args *args);
int	   len_z(t_params *params, t_args *args);
int    len_j(t_params *params, t_args *args);
int	   len_hh(t_params *params, t_args *args);
int    len_ll(t_params *params, t_args *args);


					/*CONVERT*/
void    convert_octal(unsigned int nb);
void    convert_hexlow(unsigned int nb);
#endif
