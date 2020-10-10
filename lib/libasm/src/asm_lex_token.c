/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:27:18 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/10 17:06:12 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token	*asm_lex_new_token(t_asm_tkn_type type)
{
	t_asm_token	*new_token;

	if (!(new_token = (t_asm_token*)malloc(sizeof(t_asm_token))))
		asm_sys_error();
	new_token->data = NULL;
	new_token->next = NULL;
	new_token->type = type;
	new_token->type_conv = TC_STR;
	return (new_token);
}

void		asm_lex_del_token(t_asm_token **token)
{
	if (!token || !(*token))
		return ;
	if ((*token)->data)
	{
		free((*token)->data);
		(*token)->data = NULL;
	}
	(*token)->type = 0;
	(*token)->type_conv = 0;
	(*token)->next = NULL;
	free(*token);
	token = NULL;
}
