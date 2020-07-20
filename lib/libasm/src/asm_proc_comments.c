/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_proc_comments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:18:21 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/20 15:40:47 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static size_t	asm_get_comment_size(char *comment)
{
	size_t		size;

	if (!comment || !*comment)
		return (0);
	size = 0;
	while (!(comment[size] == '\n' || comment[size] == '\0'))
		size++;
	return (size);
}

static char		*asm_comment_to_str(t_asm_string *asm_str)
{
	char	*comment;
	size_t	size;

	asm_str->index++;
	size = asm_get_comment_size(asm_str->str + asm_str->index);
	if (!(comment = ft_strnew(size)))
		asm_sys_error();
	ft_memcpy(comment, asm_str->str + asm_str->index, size);
	asm_str->index += size;
	asm_str->char_num += size;
	return (comment);
}

t_asm_token 	*asm_proc_comments(t_asm_string *asm_str)
{
	char		*comment;
	t_asm_token	*token;

	comment = asm_comment_to_str(asm_str);
	token = asm_new_token(TT_COMMENT);
	token->data = (void*)comment;
	return (token);
}
