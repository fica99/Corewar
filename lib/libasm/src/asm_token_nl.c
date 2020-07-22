/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:55:24 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/22 15:58:41 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token	*asm_token_nl(t_asm_string *asm_str)
{
	asm_str->line_num++;
	asm_str->char_num = 0;
	asm_str->index++;
	return (asm_new_token(TT_NEWLINE));
}
