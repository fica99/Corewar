/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_chain_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:38:31 by olegmulko         #+#    #+#             */
/*   Updated: 2020/09/15 20:21:42 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token		*asm_get_chain_tokens(t_asm_string *asm_str)
{
	t_asm_token	*head;
	t_asm_token	*next;

	head = asm_get_token(asm_str);
	if (head->type == TT_EOF)
		return (head);
	next = head;
	while (next->type != TT_EOF)
	{
		next->next = asm_get_token(asm_str);
		next = next->next;
	}
	return (head);
}
