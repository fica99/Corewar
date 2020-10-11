/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:15:14 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/11 14:13:35 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_asm_pars_prms	*asm_init_pars_prms(void)
{
	t_asm_pars_prms	*prms;

	if (!(prms = (t_asm_pars_prms *)malloc(
		sizeof(t_asm_pars_prms))))
		asm_sys_error();
	prms->exec_code_size = 0;
	prms->line_num = 1;
	prms->char_num = 1;
	prms->error = NULL;
	return (prms);
}

int				asm_skip_token(t_asm_token **token, t_asm_tkn_type type)
{
	if ((*token)->type == type)
	{
		(*token) = (*token)->next;
		return (1);
	}
	return (0);
}

int				asm_parser(t_asm_token *token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	int			parsed_name;
	int			parsed_comment;

	(void)prms;
	parsed_name = 0;
	parsed_comment = 0;
	bin_data->add(bin_data, COREWAR_EXEC_MAGIC, 8);
	while (!parsed_name || !parsed_comment)
	{
		if (asm_skip_token(&token, TT_SEP)
			|| asm_skip_token(&token, TT_NEWLINE))
			continue ;
		else if (token->type == TT_CHAMP_NAME && !parsed_name)
			parsed_name = asm_pars_champ_name(&token, bin_data, prms);
		else if (token->type == TT_CHAMP_COMMENT && !parsed_comment)
			parsed_comment = asm_pars_champ_comment(&token, bin_data, prms);
		else
			return (0);
	}
	return (asm_exec_code(&token, bin_data, prms));
}
