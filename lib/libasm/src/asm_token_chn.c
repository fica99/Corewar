/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_chn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:07:14 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/23 11:21:56 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int					asm_check_champ_name(t_asm_string *asm_str)
{
	static char		*champ_name = NAME_CMD_STRING;
	static size_t	size;

	if (!size)
		size = ft_strlen(champ_name);
	if (!ft_strncmp(champ_name, asm_str->str + asm_str->index, size))
		return (1);
	return (0);
}

t_asm_token			*asm_token_champ_name(t_asm_string *asm_str)
{
	t_asm_token		*token;
	static size_t	size;

	if (!size)
		size = ft_strlen(NAME_CMD_STRING);
	token = asm_new_token(TT_CHAMP_NAME);
	asm_str->index += size;
	asm_str->char_num += size;
	return (token);
}
