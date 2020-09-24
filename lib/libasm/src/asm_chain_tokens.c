/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_chain_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:38:31 by olegmulko         #+#    #+#             */
/*   Updated: 2020/09/24 20:48:34 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token		*asm_get_chain_tokens(t_asm_string *asm_str,
											t_hash **opers_hash)
{
	t_asm_token	*head;
	t_asm_token	*next;

	head = asm_get_token(asm_str, opers_hash);
	if (head->type == TT_EOF)
		return (head);
	next = head;
	while (next->type != TT_EOF)
	{
		next->next = asm_get_token(asm_str, opers_hash);
		next = next->next;
	}
	return (head);
}
