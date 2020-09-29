/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:35:08 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/29 20:58:17 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_is_label(char *str, size_t i, int mod)
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

char			*asm_get_label_str(t_asm_string *asm_str, char mod)
{
	size_t		i;
	char		*label;
	size_t		delta;

	if (mod == -1)
		asm_str->index++;
	i = asm_str->index;
	while (ft_strchr(LABEL_CHARS, asm_str->str[i]))
	{
		i++;
		continue ;
	}
	delta = i - asm_str->index;
	label = ft_strnew(delta);
	ft_memcpy(label, asm_str->str + asm_str->index, delta);
	i += (mod == 1) ? 1 : 0;
	asm_str->index += i;
	asm_str->char_num += i;
	return (label);
}

t_asm_token		*asm_token_label(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_lex_new_token(TT_LABEL);
	token->data = (void *)(asm_get_label_str(asm_str, 1));
	return (token);
}
