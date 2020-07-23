/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 09:30:41 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/23 11:19:21 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	asm_check_sep(t_asm_string *asm_str)
{
	if (asm_str->str[asm_str->index] == ' '
		|| asm_str->str[asm_str->index] == '\t')
	{
		asm_str->index++;
		asm_str->char_num++;
		return (1);
	}
	return (0);
}

t_asm_token	*asm_get_token(t_asm_string *asm_str)
{
	while (asm_str->str[asm_str->index])
	{
		if (asm_check_sep(asm_str))
			continue ;
		else if (asm_str->str[asm_str->index] == '\n')
			return (asm_token_nl(asm_str));
		else if (asm_str->str[asm_str->index] == COMMENT_CHAR
			|| asm_str->str[asm_str->index] == ALT_COMMENT_CHAR)
			return (asm_token_comment(asm_str));
		else if (asm_str->str[asm_str->index] == '"')
			return (asm_token_str(asm_str));
		else if (asm_check_champ_name(asm_str))
			return (asm_token_champ_name(asm_str));
		else
			asm_lex_error(asm_str, ERR_LEX);
	}
	return (asm_new_token(TT_EOF));
}
