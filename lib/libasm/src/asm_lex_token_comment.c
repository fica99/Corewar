/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:47:47 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/10 17:58:58 by ggrimes          ###   ########.fr       */
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
	return (token);
}

t_asm_token		*asm_lex_del_com_token(t_asm_token *token)
{
	t_asm_token	*comment_token;

	if (!token)
		asm_prog_error(ERR_NULL_POINTER);
	if (token->type == TT_COMMENT)
	{
		comment_token = token;
		token = comment_token->next;
		asm_lex_del_token(&comment_token);
		return (token);
	}
	comment_token = token->next;
	if (comment_token->type == TT_COMMENT)
	{
		token->next = comment_token->next;
		asm_lex_del_token(&comment_token);
	}
	return (token);
}

t_asm_token		*asm_lex_del_all_com_tokens(t_asm_token *token)
{
	t_asm_token	*head;

	if (!token)
		asm_prog_error(ERR_NULL_POINTER);
	token = asm_lex_del_com_token(token);
	head = token;
	while (token->type != TT_EOF)
	{
		asm_lex_del_com_token(token);
		token = token->next;
	}
	return (head);
}
