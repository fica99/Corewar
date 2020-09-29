/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_arg_ind.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:41:44 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/29 21:46:06 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_arg_ind(t_asm_string *asm_str)
{
	if (asm_is_number(asm_str, asm_str->index)
		|| asm_lex_is_label(asm_str->str, asm_str->index, -1))
		return (1);
	return (0);
}

t_asm_token		*asm_token_arg_ind(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_lex_new_token(TT_ARG_IND);
	if (asm_str->str[asm_str->index] == LABEL_CHAR)
	{
		token->data = (void *)asm_lex_get_label_str(asm_str, -1);
		token->type_conv = TC_STR;
	}
	else
	{
		token->data = (void *)asm_get_number(asm_str);
		token->type_conv = TC_SIZE_T;
	}
	return (token);
}
