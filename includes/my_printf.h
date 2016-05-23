#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <inttypes.h>
# include "../libft/Includes/libft.h"
# include <stdio.h>

# define SPECIFIER 14
# define LENGHT 6


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
	int					count_flags;
}						t_params;

typedef struct			s_tabvar
{
	wchar_t				*var_wstr;
	wchar_t				var_wint;
	unsigned short		var_unshort;
	char				var_c;
	signed char			var_signedc;
	unsigned char		var_unchar;
	char				*var_str;
	int					var_int;
	short				var_short;
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
	int					j;
	int					(*f)(int , t_args *,t_tabvar *);
}						t_lght;

int		ft_printf(const char *format, ...);

					/*PRINT*/
int		ft_printchar(char c, t_params *params);
int		ft_printwchar(wchar_t *wstr, t_params *params);
int		printnbr(int nb, t_params *params);
int		ft_print_memory(t_params *params, void *addr);
int		print_add(t_params *params, t_args *args, t_tabvar *var);
int		print_integers_lenght(int lght,t_args *args, t_tabvar *var);

					/*PARSING */
int 	flags(const char *str, int pos, t_params *params);
int		init_width(const char *str, int pos, t_params *params);
int		get_precision(const char *str, int pos, t_params *params);
int 	lenght_gest(const char *str);
int		specifier(char format);

					/*DEFINE VARIABLE USE*/
int		my_printf(t_params *params, t_args *args);
int		specifier_integer(t_params *params, t_args *args, t_tabvar *var);
int     specifier_s(t_params *params, t_args *args, t_tabvar *var);
int     specifier_S(t_params *params, t_args *args, t_tabvar *var);
int     specifier_c(t_params *params, t_args *args, t_tabvar *var);
int		specifier_C(t_params *params, t_args *args, t_tabvar *var);
int     specifier_integer(t_params *params, t_args *args, t_tabvar *var);
int     specifier_spint(t_params *params, t_args *args, t_tabvar *var);
int     specifier_slong(t_params *params, t_args *args, t_tabvar *var);

int		lenght_T(int specifier, t_args *args, t_tabvar *var);
int		lenght_h(int specifier, t_args *args, t_tabvar *var);
int		lenght_l(int specifier, t_args *args, t_tabvar *var);
int		lenght_L(int specifier, t_args *args, t_tabvar *var);
int		lenght_j(int specifier, t_args *args, t_tabvar *var);
int		lenght_z(int specifier, t_args *args, t_tabvar *var);
int		lenght_hh(int specifier, t_args *args, t_tabvar *var);
int		lenght_ll(int specifier, t_args *args, t_tabvar *var);

					/*CONVERT*/
int     convert_ushctal(unsigned short nb, int size_nb);
int     convert_uloctal(unsigned long long nb, int size_nb);
int		convert_loctal(long long nb, int size_nb);
int		convert_octal(unsigned int nb, int size_nb);
int		convert_hx(unsigned int nb, int size_nb, int maj);
int   	convert_unlhx(unsigned long long nb, int size_nb, int maj);

#endif
