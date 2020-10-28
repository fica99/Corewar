/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_arg_ind.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:02:57 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 22:36:48 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_lex_is_arg_ind(t_asm_string *asm_str)
{
	if (asm_lex_is_number(asm_str, asm_str->index)
			|| asm_lex_is_label(asm_str->str, asm_str->index, -1))
		return (1);
	return (0);
}

t_asm_token		*asm_lex_token_arg_ind(t_asm_string *asm_str)
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
		token->data = (void *)asm_lex_get_number(asm_str);
		token->type_conv = TC_SIZE_T;
	}
	return (token);
}
