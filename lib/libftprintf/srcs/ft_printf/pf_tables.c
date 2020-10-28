/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:51:10 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/28 21:15:17 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_flags		*pf_flags_table(void)
{
	static char			is_init;
	static t_pf_flags	table[ASCII_SIZE];

	if (!is_init)
	{
		table['#'] = PF_FL_HASH;
		table['-'] = PF_FL_MINUS;
		table['0'] = PF_FL_ZERO;
		table['+'] = PF_FL_PLUS;
		table[' '] = PF_FL_SPACE;
		table['b'] = PF_FL_BIN;
		is_init = TRUE;
	}
	return (table);
}

t_pf_mod_len	*pf_mod_table(void)
{
	static char			is_init;
	static t_pf_mod_len	table[ASCII_SIZE];

	if (!is_init)
	{
		table['l'] = PF_ML_L;
		table['L'] = PF_ML_BL;
		table['h'] = PF_ML_H;
		table['j'] = PF_ML_J;
		table['z'] = PF_ML_Z;
		table['t'] = PF_ML_Z;
		is_init = TRUE;
	}
	return (table);
}

void			*pf_spec_table(const char c)
{
	static char		is_init;
	static void		*table[ASCII_SIZE];

	if (!is_init)
	{
		table['c'] = (void*)&pf_spec_c;
		table['C'] = (void*)&pf_spec_c;
		table['%'] = (void*)&pf_spec_percent;
		table['s'] = (void*)&pf_spec_s;
		table['d'] = (void*)&pf_spec_int;
		table['i'] = (void*)&pf_spec_int;
		table['p'] = (void*)&pf_spec_p;
		table['x'] = (void*)&pf_spec_small_x;
		table['X'] = (void*)&pf_spec_big_x;
		table['o'] = (void*)&pf_spec_o;
		table['u'] = (void*)&pf_spec_uint;
		table['f'] = (void*)&pf_spec_small_f;
		is_init = TRUE;
	}
	return (table[(size_t)c]);
}
