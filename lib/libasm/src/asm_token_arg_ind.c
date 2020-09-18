/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_arg_ind.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:41:44 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/18 15:11:21 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_arg_ind(t_asm_string *asm_str)
{
	if (asm_is_number(asm_str)
		|| asm_is_label(asm_str))
		return (1);
	return (0);
}

t_asm_token		*asm_token_arg_ind(t_asm_string *asm_str)
{
	t_asm_token	*token;
	(void)asm_str;

	token = asm_new_token(TT_ARG_IND);
	return (token);
}
