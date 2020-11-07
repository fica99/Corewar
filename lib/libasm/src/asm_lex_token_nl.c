/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_nl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:37:59 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 23:18:01 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token	*asm_lex_token_nl(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_lex_new_token(TT_NEWLINE);
	asm_pos_to_token(asm_str, token);
	asm_str->line_num++;
	asm_str->char_num = 1;
	asm_str->index++;
	return (token);
}
