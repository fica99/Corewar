/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:15:14 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/03 22:51:33 by olegmulko        ###   ########.fr       */
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
	prms->args_mask = 0;
	prms->mask_offset = 0;
	prms->dir_size = 0;
	prms->oper_byte_index = 0;
	prms->labels = NULL;
	prms->line_num = 1;
	prms->char_num = 1;
	prms->error = NULL;
	return (prms);
}

void			asm_fill_prms_from_token(t_asm_token *token,
	t_asm_pars_prms *prms, char *error)
{
	if (!token || !prms)
		asm_prog_error(ERR_NULL_POINTER);
	if (!(prms->error = ft_strdup(error)))
		asm_sys_error();
	prms->line_num = token->line_num;
	prms->char_num = token->char_num;
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

static int		asm_header_error(t_asm_token *token, t_asm_pars_prms *prms,
	int parsed_name, int parsed_comment)
{
	if (parsed_name == 1)
		return (asm_parser_error(token, prms, ASM_ERR_CHAMP_NAME));
	else if (parsed_comment == 1)
		return (asm_parser_error(token, prms, ASM_ERR_CHAMP_COMMENT));
	else
		return (asm_parser_error(token, prms, ASM_ERR_GENERAL));
}

int				asm_parser(t_asm_token *token,
	t_asm_bin_data *bin_data, t_asm_pars_prms *prms)
{
	int			parsed_name;
	int			parsed_comment;

	parsed_name = 0;
	parsed_comment = 0;
	bin_data->add(bin_data, COREWAR_EXEC_MAGIC, 8);
	while (parsed_name != 1 || parsed_comment != 1)
	{
		if (asm_skip_token(&token, TT_SEP)
			|| asm_skip_token(&token, TT_NEWLINE))
			continue ;
		else if (token->type == TT_CHAMP_NAME && !parsed_name)
			parsed_name = asm_pars_champ_name(&token, bin_data, prms);
		else if (token->type == TT_CHAMP_COMMENT && !parsed_comment)
			parsed_comment = asm_pars_champ_comment(&token, bin_data, prms);
		else
			return (asm_header_error(token, prms, parsed_name, parsed_comment));
		if (parsed_name == -1 || parsed_comment == -1)
			return (-1);
	}
	return (asm_exec_code(&token, bin_data, prms));
}
