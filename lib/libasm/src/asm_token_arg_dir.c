/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_arg_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:32:26 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/22 20:17:22 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_arg_dir(t_asm_string *asm_str)
{
	size_t		i;

	i = asm_str->index;
	if (asm_str->str[i++] != DIRECT_CHAR)
		return (0);
	return (asm_is_label(asm_str->str, i, -1)
		|| asm_is_number(asm_str, i));
}

t_asm_token		*asm_token_arg_dir(t_asm_string *asm_str)
{
	t_asm_token	*token;

	asm_str->index++;
	asm_str->char_num++;
	token = asm_new_token(TT_ARG_DIR);
	if (asm_str->str[asm_str->index] == LABEL_CHAR)
	{
		token->data = (void *)asm_get_label_str(asm_str, -1);
		token->type_conv = TC_STR;
	}
	else
	{
		token->data = (void *)asm_get_number(asm_str);
		token->type_conv = TC_SIZE_T;
	}
	return (token);
}
