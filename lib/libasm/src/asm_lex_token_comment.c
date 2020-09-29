/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:47:47 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/29 21:48:38 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static size_t	asm_lex_get_comment_size(char *comment)
{
	size_t		size;

	if (!comment || !*comment)
		return (0);
	size = 0;
	while (!(comment[size] == '\n' || comment[size] == '\0'))
		size++;
	return (size);
}

static char		*asm_lex_comment_to_str(t_asm_string *asm_str)
{
	char	*comment;
	size_t	size;

	asm_str->index++;
	size = asm_lex_get_comment_size(asm_str->str + asm_str->index);
	if (!(comment = ft_strnew(size)))
		asm_sys_error();
	ft_memcpy(comment, asm_str->str + asm_str->index, size);
	asm_str->index += size;
	asm_str->char_num += size;
	return (comment);
}

t_asm_token		*asm_lex_token_comment(t_asm_string *asm_str)
{
	char		*comment;
	t_asm_token	*token;

	comment = asm_lex_comment_to_str(asm_str);
	token = asm_lex_new_token(TT_COMMENT);
	token->data = (void*)comment;
	token->size = ft_strlen(comment);
	return (token);
}
