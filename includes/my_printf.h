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
# define UNSHORT unsigned short
# define UNLLONG unsigned long long
# define UNCHAR unsigned char
# define LLONG long long
# define UNINT unsigned int
# define SIGCHAR signed char

typedef struct		s_args
{
	va_list			ap;
	va_list			tmp_ap;
}					t_args;

typedef struct		s_params
{
	int				width;
	int				precision;
	int				lenght;
	int				specifier;
	int				count_flags;
	int				count_tflags;
	int				flags;
	int				neg;
	int				pos;
	int				pos_nb;
	int				neg_nb;
	int				tflags;
}					t_params;

typedef struct		s_tabvar
{
	wchar_t			*var_wstr;
	wchar_t			var_wint;
	UNSHORT			var_unshort;
	char			var_c;
	UNCHAR			var_unchar;
	char			*var_str;
	int				var_int;
	short			var_short;
	LLONG			var_longlong;
	UNINT			var_unsint;
	UNLLONG			var_unlonglong;
	SIGCHAR			var_signedc;
	double			var_double;
}					t_tabvar;

typedef struct		s_tab
{
	int				i;
	int				(*f)(t_params *, t_args *, t_tabvar *);
}					t_tab;

typedef struct		s_lght
{
	int				j;
	int				(*f)(int, t_args *, t_tabvar *, t_params *);
}					t_lght;

int					ft_printf(const char *format, ...);

int					ft_printchar(char c, t_params *params);
int					ft_printstr(char *str, t_params *params);
int					ft_printwchar(wchar_t *wstr, t_params *params);
int					printnbr(int nb, t_params *params);
int					ft_print_memory(t_params *params, void *addr);
int					print_add(t_params *params, t_args *args, t_tabvar *var);
int					print_integers_lenght(int lght, t_args *args,
											t_tabvar *var);
int					flags_print(t_params *params, int ref);
int					space_print(t_params *params, int nb);
int					sharp_printhx(int nb, int maj, int tmp);
int					sharp_printoc(int nb, int tmp);
int					space_printoc(t_params *params, int tmp, int nb);
int					space_printhx(t_params *params, int tmp, int nb, int maj);

int					flags(const char *str, int pos, t_params *params);
int					init_width(const char *str, int pos, t_params *params);
int					get_precision(const char *str, int pos, t_params *params);
int					lenght_gest(const char *str);
int					specifier(char format);
int					space(const char *str, int pos, t_params *params);
int					zero_size(const char *str, int pos, t_params *params);

int					my_printf(t_params *params, t_args *args);
int					specifier_integer(t_params *params, t_args *args,
										t_tabvar *var);
int					specifier_s(t_params *params, t_args *args, t_tabvar *var);
int					specifier_ss(t_params *params, t_args *args, t_tabvar *var);
int					specifier_c(t_params *params, t_args *args, t_tabvar *var);
int					specifier_cc(t_params *params, t_args *args, t_tabvar *var);
int					specifier_integer(t_params *params, t_args *args,
										t_tabvar *var);
int					specifier_spint(t_params *params, t_args *args,
									t_tabvar *var);
int					specifier_slong(t_params *params, t_args *args,
									t_tabvar *var);
int					lenght_h(int sp, t_args *args, t_tabvar *var, t_params *p);
int					lenght_l(int sp, t_args *args, t_tabvar *var, t_params *p);
int					lenght_j(int sp, t_args *args, t_tabvar *var, t_params *p);
int					lenght_z(int sp, t_args *args, t_tabvar *var, t_params *p);
int					lenght_hh(int sp, t_args *args, t_tabvar *var, t_params *p);
int					lenght_ll(int sp, t_args *args, t_tabvar *var, t_params *p);

void				printhex(size_t nb, char *base);
void				printoctal(size_t nb, char *base);
int					cthex(size_t nb, char *base);
int					ctoctal(size_t nb, char *base);
int					con_ushctal(unsigned short nb, t_params *params);
int					con_uloctal(unsigned long long nb, t_params *params);
int					con_loctal(long long nb, t_params *params);
int					con_octal(unsigned int nb, t_params *params);
int					con_hx(unsigned int nb, int maj, t_params *params);
int					con_unlhx(unsigned long long nb, int maj, t_params *p);

#endif
