#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include "../libft/Includes/libft.h"
# include <stdio.h>

# define SPECIFIER 16
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

typedef struct			s_tabvar
{
	wchar_t				*var_wstr;
	wchar_t				var_wint;
	char				var_c;
	char				*var_str;
	int					var_int;
	long long			var_longlong;
	unsigned int		var_unsint;
	unsigned long long	var_unlonglong;
	double				var_double;
}						t_tabvar;

typedef struct			s_tab
{
	int					i;
	int 				(*f)(t_params *, t_args *, t_tabvar *);
}						t_tab;

typedef struct			s_lght
{
	int					i;
	int					(*f)(t_tabvar *);
}						t_lght;

int		ft_printf(const char *format, ...);

					/*PRINT*/
void 	printf_gest(va_list ap, int pos);
void	gest_error(va_list ap, int pos);
void    display(void *var, t_params *params);
void 	display_char(char *var, t_params *params);
int		ft_print_memory(void *addr, size_t size);
int		print_add(t_params *params, t_args *args, t_tabvar *var);
int		print_integers_lenght(int lght,t_args *args, t_tabvar *var);

					/*PARSING */
int 	flags(const char *str, int pos, t_params *params);
int		init_width(const char *str, int pos, t_params *params);
int		get_precision(const char *str, int pos, t_params *params);
int 	lenght_gest(const char *str);
int		specifier(char format);

					/*DEFINE VARIABLE USE*/
int		my_printf(t_params *params, t_args *args, t_tabvar *var);
int		specifier_integer(t_params *params, t_args *args, t_tabvar *var);
int     specifier_s(t_params *params, t_args *args, t_tabvar *var);
int     specifier_S(t_params *params, t_args *args, t_tabvar *var);
int     specifier_c(t_params *params, t_args *args, t_tabvar *var);
int		specifier_C(t_params *params, t_args *args, t_tabvar *var);
int     specifier_integer(t_params *params, t_args *args, t_tabvar *var);
int     specifier_spint(t_params *params, t_args *args, t_tabvar *var);
int     specifier_float(t_params *params, t_args *args, t_tabvar *var);

int		lenght_t(t_tabvar *var);
int		lenght_h(t_tabvar *var);
int		lenght_l(t_tabvar *var);
int		lenght_L(t_tabvar *var);
int		lenght_j(t_tabvar *var);
int		lenght_z(t_tabvar *var);
int		lenght_hh(t_tabvar *var);
int		lenght_ll(t_tabvar *var);

					/*CONVERT*/
int        convert_octal(unsigned int nb, int size_nb);
int    convert_hx(unsigned int nb, int size_nb, int maj);

#endif
