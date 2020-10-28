/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_sep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:34:15 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 23:16:28 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_lex_is_sep(t_asm_string *asm_str)
{
	if (asm_str->str[asm_str->index] == ' '
			|| asm_str->str[asm_str->index] == '\t')
		return (1);
	return (0);
}

t_asm_token		*asm_lex_token_sep(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_lex_new_token(TT_SEP);
	asm_pos_to_token(asm_str, token);
	asm_str->index++;
	asm_str->char_num++;
	return (token);
}
