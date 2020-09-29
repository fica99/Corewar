/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_chain_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:56:25 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/29 20:12:03 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token		*asm_lex_chain_tokens(t_asm_string *asm_str,
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
