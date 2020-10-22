/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_chain_tokens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:41:05 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/15 20:22:32 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_token		*asm_lex_get_chain_tokens(t_asm_string *asm_str,
											t_hash **opers_hash)
{
	t_asm_token	*head;
	t_asm_token	*next;

	head = asm_lex_get_token(asm_str, opers_hash);
	if (head->type == TT_EOF)
		return (head);
	next = head;
	while (next->type != TT_EOF)
	{
		next->next = asm_lex_get_token(asm_str, opers_hash);
		next = next->next;
	}
	return (head);
}
