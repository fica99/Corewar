/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:21:15 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/11 13:00:31 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void		asm_lex_check_end_str(t_asm_string *asm_str)
{
	if (asm_str->str[asm_str->index] == '"')
	{
		asm_str->index++;
		asm_str->char_num++;
	}
}

static size_t	asm_lex_check_str_size(t_asm_string *asm_str)
{
	size_t		size;

	size = 0;
	if (asm_str->str[asm_str->index] == '"')
	{
		asm_str->index++;
		asm_str->char_num++;
	}
	while (asm_str->str[asm_str->index])
	{
		if (asm_str->str[asm_str->index] == '"')
			return (size);
		if (asm_str->str[asm_str->index] == '\n')
		{
			asm_str->line_num++;
			asm_str->char_num = 0;
		}
		size++;
		asm_str->index++;
		asm_str->char_num++;
	}
	asm_lex_error(asm_str, ERR_STR_CLOSE);
	return (0);
}

t_asm_token		*asm_lex_token_str(t_asm_string *asm_str)
{
	size_t		size;
	char		*str;
	t_asm_token	*token;
	size_t		offset;

	offset = asm_str->index + 1;
	size = asm_lex_check_str_size(asm_str);
	if (!(str = ft_strnew(size)))
		asm_sys_error();
	ft_memcpy(str, asm_str->str + offset, size);
	token = asm_lex_new_token(TT_STRING);
	token->data = (void*)str;
	asm_lex_check_end_str(asm_str);
	return (token);
}
