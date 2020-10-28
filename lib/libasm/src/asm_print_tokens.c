/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_print_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:03:52 by sschmele          #+#    #+#             */
/*   Updated: 2020/10/28 22:49:09 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	asm_print_tokens(t_asm_token *tokens)
{
	t_asm_token	*next;
	char		*delim;

	next = tokens;
	delim = "---------------------------------------";
	while (next->type != TT_EOF)
	{
		if (next->type == TT_SEP || next->type == TT_NEWLINE)
		{
			next = next->next;
			continue ;
		}
		printf("%s\n", delim);
		printf("token:");
		if (next->type == TT_STRING)
			printf("string, ");
		else if (next->type == TT_COMMENT)
			printf("comment, ");
		else if (next->type == TT_CHAMP_NAME)
			printf("champion name, ");
		else if (next->type == TT_LABEL)
			printf("label, ");
		else if (next->type == TT_ARG_REG)
			printf("arg register, ");
		else if (next->type == TT_ARG_DIR)
			printf("arg direct label, ");
		else if (next->type == TT_ARG_IND)
			printf("arg indirect label, ");
		else if (next->type == TT_OPER)
			printf("operation, ");
		else if (next->type == TT_ARG_SEP)
			printf("arg separator, ");
		if (next->data)
		{
			if (next->type_conv == TC_STR)
				printf("%s\n", (char*)next->data);
			else
				printf("%d\n", *(int*)next->data);
			
		}
		next = next->next;
	}
	printf("\n");
}
