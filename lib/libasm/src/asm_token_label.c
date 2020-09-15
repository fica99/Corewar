/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:35:08 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/15 21:09:38 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_label(t_asm_string *asm_str)
{
	size_t	i;

	i = asm_str->index;
	while (asm_str->str[i])
	{
		if (asm_str->str[i] == LABEL_CHAR)
			break ;
		if (!ft_strchr(LABEL_CHARS, asm_str->str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_asm_token		*asm_token_label(t_asm_string *asm_str)
{
	t_asm_token	*token;
	size_t		i;
	size_t		delta;
	char		*label;

	token = asm_new_token(TT_LABEL);
	i = asm_str->index;
	while (asm_str->str[i] != LABEL_CHAR)
	{
		i++;
		continue ;
	}
	delta = i - asm_str->index;
	label = ft_strnew(delta);
	ft_memcpy(label, asm_str->str + asm_str->index, delta);
	token->data = (void *)(label);
	token->size = delta;
	asm_str->index = i + 1;
	asm_str->char_num += i + 1;
	return (token);
}
