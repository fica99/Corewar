/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:14:01 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/23 09:17:25 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token	*asm_new_token(t_asm_tkn_type type)
{
	t_asm_token	*new_token;

	if (!(new_token = (t_asm_token*)malloc(sizeof(t_asm_token))))
		asm_sys_error();
	new_token->data = NULL;
	new_token->next = NULL;
	new_token->type = type;
	new_token->size = 0;
	return (new_token);
}
