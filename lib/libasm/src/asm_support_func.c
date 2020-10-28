/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_support_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:21:14 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/28 23:15:26 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_add_null_in_bd(t_asm_bin_data *bin_data, int bytes)
{
	bin_data->add(bin_data, 0, 2 * bytes);
}

void	asm_pos_to_token(t_asm_string *asm_str, t_asm_token *token)
{
	if (!asm_str || !token)
		asm_prog_error(ERR_NULL_POINTER);
	token->line_num = asm_str->line_num;
	token->char_num = asm_str->char_num;
}
