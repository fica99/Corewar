/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_chcom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:19:31 by olegmulko         #+#    #+#             */
/*   Updated: 2020/09/29 20:58:17 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int					asm_check_champ_comment(t_asm_string *asm_str)
{
	static char		*champ_name = COMMENT_CMD_STRING;
	static size_t	size;

	if (!size)
		size = ft_strlen(champ_name);
	if (!ft_strncmp(champ_name, asm_str->str + asm_str->index, size))
		return (1);
	return (0);
}

t_asm_token			*asm_token_champ_comment(t_asm_string *asm_str)
{
	t_asm_token		*token;
	static size_t	size;

	if (!size)
		size = ft_strlen(COMMENT_CMD_STRING);
	token = asm_lex_new_token(TT_CHAMP_COMMENT);
	asm_str->index += size;
	asm_str->char_num += size;
	return (token);
}
