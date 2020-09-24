/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:57:47 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/24 22:08:53 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int		asm_is_low(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int				asm_is_oper(t_asm_string *asm_str, t_hash **opers_hash)
{
	size_t		size;
	size_t		i;
	char		*name;
	void		*res;

	i = asm_str->index;
	while (asm_is_low(asm_str->str[i]))
		i++;
	if (!(size = i - asm_str->index))
		return (0);
	if (!(name = ft_strsub(asm_str->str, asm_str->index, size)))
		asm_sys_error();
	res = get_hash_data(opers_hash, name, OPERS_SIZE);
	ft_memdel((void **)&name);
	if (res)
		return (1);
	return (0);
}
