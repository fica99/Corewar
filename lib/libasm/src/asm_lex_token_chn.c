/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_chn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:21:21 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/28 23:19:30 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int					asm_lex_is_champ_name(t_asm_string *asm_str)
{
	static char		*champ_name = NAME_CMD_STRING;
	static size_t	size;

	if (!size)
		size = ft_strlen(champ_name);
	if (!ft_strncmp(champ_name, asm_str->str + asm_str->index, size))
		return (1);
	return (0);
}

t_asm_token			*asm_lex_token_champ_name(t_asm_string *asm_str)
{
	t_asm_token		*token;
	static size_t	size;

	if (!size)
		size = ft_strlen(NAME_CMD_STRING);
	token = asm_lex_new_token(TT_CHAMP_NAME);
	asm_pos_to_token(asm_str, token);
	asm_str->index += size;
	asm_str->char_num += size;
	return (token);
}
