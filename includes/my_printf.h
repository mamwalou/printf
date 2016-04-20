#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include <wchar.h>
# include "../libft/Includes/libft.h"
# include <stdio.h>

# define SPECIFIER 14
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

int		ft_printf(const char *format, ...);

					/*PRINT*/
void 	printf_gest(va_list ap, int pos);
void	gest_error(va_list ap, int pos);
void    display(void *var, t_params *params);
void 	display_char(char *var, t_params *params);
int		ft_print_memory(void *addr, size_t size);

					/*PARSING */
int 	flags(const char *str, int pos, t_params *params);
int		init_width(const char *str, int pos, t_params *params);
int		get_precision(const char *str, int pos, t_params *params);
int 	lenght_gest(const char *str);
int		specifier(char format);

					/*DEFINE VARIABLE USE*/
int		my_printf(t_params *params, t_args *args);
int		specifier_integer(t_params *params, t_args *args);
int     specifier_s(t_params *params, t_args *args);
int     specifier_S(t_params *params, t_args *args);
int     specifier_c(t_params *params, t_args *args);
int		specifier_C(t_params *params, t_args *args);
int     specifier_integer(t_params *params, t_args *args);
int     specifier_spint(t_params *params, t_args *args);
int     specifier_float(t_params *params, t_args *args);
int		print_add(t_params *params, t_args *args);

					/*CONVERT*/
void    convert_octal(unsigned int nb);
void    convert_hexlow(unsigned int nb, int size_nb, int maj);

#endif
