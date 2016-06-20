/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_def.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 18:45:26 by sbeline           #+#    #+#             */
/*   Updated: 2016/06/20 18:45:28 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static const t_tab		g_tab[SPECIFIER] =
{
	{0, specifier_s},
	{1, specifier_ss},
	{2, specifier_c},
	{3, specifier_cc},
	{4, specifier_integer},
	{5, specifier_integer},
	{6, specifier_integer},
	{7, specifier_spint},
	{8, specifier_integer},
	{9, specifier_spint},
	{10, specifier_slong},
	{11, specifier_spint},
	{12, specifier_spint},
	{13, print_add},
};

static t_lght		g_lght[LENGHT] =
{
	{0, lenght_h},
	{1, lenght_l},
	{2, lenght_j},
	{3, lenght_z},
	{4, lenght_hh},
	{5, lenght_ll},
};

static void			init_var(t_tabvar *var)
{
	var->var_unchar = 0;
	var->var_unshort = 0;
	var->var_wstr = NULL;
	var->var_wint = 0;
	var->var_short = 0;
	var->var_c = 0;
	var->var_str = 0;
	var->var_int = 0;
	var->var_longlong = 0;
	var->var_unsint = 0;
	var->var_unlonglong = 0;
	var->var_double = 0;
}

int					my_printf(t_params *params, t_args *args)
{
	t_tabvar		var;
	int				i;
	int				j;
	int				count;

	i = 0;
	j = 0;
	count = 0;
	init_var(&var);
	while (g_tab[i].i != params->specifier && i <= SPECIFIER)
		i++;
	if (i > SPECIFIER)
		return (-1);
	if (params->lenght == LENGHT)
		if (i < SPECIFIER)
			return (count + g_tab[i].f(params, args, &var));
	while (g_lght[j].j != params->lenght)
		j++;
	return (count + g_lght[j].f(i, args, &var, params));
}
