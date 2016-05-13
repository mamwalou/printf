/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_def.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:27:57 by sbeline           #+#    #+#             */
/*   Updated: 2016/05/13 17:43:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/my_printf.h"

static t_tab    tab[SPECIFIER]=
{
    {0, specifier_s},
    {1, specifier_S},
    {2, specifier_c},
    {3, specifier_C},
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
    {13, specifier_slong},
};

static t_lght		lght[LENGHT]=
{
	{0, lenght_h},
	{1, lenght_l},
	{2, lenght_j},
	{3, lenght_z},
	{4, lenght_hh},
	{5, lenght_ll},
};

static void 	init_var(t_tabvar *var)
{
	var->var_unchar = 0;
	var->var_unshort = 0;
	var->var_wstr = NULL;
	var->var_wint = 0;
	var->var_short = 0;
	var->var_c = 0;
	var->var_signedc = 0;
	var->var_str = 0;
	var->var_int = 0;
	var->var_longlong = 0;
	var->var_unsint = 0;
	var->var_unlonglong = 0;
	var->var_double = 0;
}

int        my_printf(t_params *params, t_args *args)
{
    int     i;
	int		j;
	t_tabvar	var;

	init_var(&var);
    i = 0;
	j = 0;
	if (params->lenght > LENGHT)
	{
    	while (tab[i].i != params->specifier && i <= SPECIFIER)
        	i++;
    	if (i <= SPECIFIER)
        	return (tab[i].f(params, args, &var));
	}
	else
	{
		while (tab[i].i != params->specifier && i <= SPECIFIER)
			i++;
		if (i > SPECIFIER)
			return (-1);
		while (lght[j].j != params->lenght)
			j++;
		return(lght[j].f(i, args, &var));
	}
	return (0);
}
