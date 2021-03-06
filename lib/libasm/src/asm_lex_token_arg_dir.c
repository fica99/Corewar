/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_arg_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:06:33 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 23:30:40 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_lex_is_arg_dir(t_asm_string *asm_str)
{
	size_t		i;

	i = asm_str->index;
	if (asm_str->str[i++] != DIRECT_CHAR)
		return (0);
	return (asm_lex_is_label(asm_str->str, i, -1)
		|| asm_lex_is_number(asm_str, i));
}

t_asm_token		*asm_lex_token_arg_dir(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_lex_new_token(TT_ARG_DIR);
	asm_pos_to_token(asm_str, token);
	asm_str->index++;
	asm_str->char_num++;
	if (asm_str->str[asm_str->index] == LABEL_CHAR)
	{
		token->data = (void *)asm_lex_get_label_str(asm_str, -1);
		token->type_conv = TC_STR;
	}
	else
	{
		token->data = (void *)asm_lex_get_number(asm_str);
		token->type_conv = TC_SIZE_T;
	}
	return (token);
}
