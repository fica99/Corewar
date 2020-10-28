/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_sep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:34:15 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 20:25:16 by sschmele         ###   ########.fr       */
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
	asm_str->index++;
	asm_str->char_num++;
	return (token);
}
