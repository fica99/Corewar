/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_type_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:07:36 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/30 00:27:41 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libasm.h"

static void	asm_write_type(char *byte, char type, char *offset)
{
	(*byte) |= type >> (*offset);
	(*offset) += 2;
}

void		asm_pars_type_args(t_asm_token *token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	char	offset;
	char	byte;

	if (!(prms->args_mask & ARG_TYPE))
		return ;
	offset = 0;
	byte = 0;
	while (1)
	{
		if (token->type == TT_ARG_REG)
			asm_write_type(&byte, ARG_TYPE_REG, &offset);
		else if (token->type == TT_ARG_DIR)
			asm_write_type(&byte, ARG_TYPE_DIR, &offset);
		else if (token->type == TT_ARG_IND)
			asm_write_type(&byte, ARG_TYPE_IND, &offset);
		else if (offset == ((ARGS_SIZE - 1) * 2)
			|| token->type == TT_NEWLINE
			|| token->type == TT_EOF)
			break ;
		else
			token = token->next;
	}
	bin_data->add(bin_data, (int)byte, 2);
}
