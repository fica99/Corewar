/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:35:08 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/18 17:02:33 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_is_label(char* str, size_t i, int mod)
{
	if (mod == -1)
	{
		if (str[i] != LABEL_CHAR)
			return (0);
		i++;
	}
	if (!ft_strchr(LABEL_CHARS, str[i++]))
		return (0);
	while (ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (mod == 1)
	{
		if (str[i] != LABEL_CHAR)
			return (0);
		i++;
	}
	return (1);
}

char			*asm_get_label_str(t_asm_string *asm_str)
{
	size_t		i;
	char		*label;
	size_t		delta;

	i = asm_str->index;
	while (asm_str->str[i] != LABEL_CHAR)
	{
		i++;
		continue ;
	}
	delta = i - asm_str->index;
	label = ft_strnew(delta);
	ft_memcpy(label, asm_str->str + asm_str->index, delta);
	asm_str->index = i + 1;
	asm_str->char_num += i + 1;
	return (label);
}

t_asm_token		*asm_token_label(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_new_token(TT_LABEL);
	token->data = (void *)(asm_get_label_str(asm_str));
	return (token);
}
