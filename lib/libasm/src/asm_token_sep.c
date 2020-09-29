/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:23:54 by olegmulko         #+#    #+#             */
/*   Updated: 2020/09/29 20:58:25 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_sep(t_asm_string *asm_str)
{
	if (asm_str->str[asm_str->index] == ' '
		|| asm_str->str[asm_str->index] == '\t')
		return (1);
	return (0);
}

t_asm_token		*asm_token_sep(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_lex_new_token(TT_SEP);
	asm_str->index++;
	asm_str->char_num++;
	return (token);
}
