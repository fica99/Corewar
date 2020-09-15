/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_arg_reg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:33:34 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/15 21:38:53 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_arg_reg(t_asm_string *asm_str)
{
	size_t		i;

	i = asm_str->index;
	if (asm_str->str[i++] != 'r')
		return (0);
	while (ft_isdigit(asm_str->str[i]))
		i++;
	if (asm_str->str[i] != SEPARATOR_CHAR
		&& asm_str->str[i] != ' '
		&& asm_str->str[i] != '\n')
		return (0);
	return (1);
}
