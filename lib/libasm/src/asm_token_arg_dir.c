/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_arg_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:32:26 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/18 15:26:40 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_arg_dir(t_asm_string *asm_str)
{
	size_t		i;

	i = asm_str->index;
	if (asm_str->str[i++] != DIRECT_CHAR)
		return (0);
	return (asm_is_label(asm_str)
		|| asm_is_label(asm_str));
}

t_asm_token		*asm_token_arg_dir(t_asm_string *asm_str)
{
	t_asm_token	*token;
	(void)asm_str;

	token = asm_new_token(TT_ARG_DIR);
	return (token);
}
