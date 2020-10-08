/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars.ch_com.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 19:46:20 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/08 20:40:56 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_add_chc_to_bd(t_asm_bin_data *bin_data,
	char *name)
{
	size_t	i;

	i = 0;
	while (name[i])
		bin_data->add(bin_data, (int)name[i++], 2);
	while (i < COMMENT_LENGTH)
	{
		bin_data->add(bin_data, 0, 2);
		i++;
	}
}

static void	asm_pars_check_chcom_token(t_asm_token **token)
{
	if ((*token)->type != TT_CHAMP_COMMENT)
		asm_prog_error(ERR_PARS_CHAMP_COMMENT_TOKEN);
	(*token) = (*token)->next;
}

void		asm_pars_champ_comment(t_asm_token *token,
	t_asm_bin_data *bin_data)
{
	char	*comment;
	size_t	size;

	while (asm_check_sep(&token) || asm_check_nl_in_loop(&token))
		;
	asm_pars_check_chcom_token(&token);
	if (token->type != TT_STRING)
		asm_prog_error("parser error");
	comment = (char *)token->data;
	if ((size = ft_strlen(comment)) > COMMENT_LENGTH)
		asm_prog_error(ERR_CHAMP_COMMENT_LEN);
	asm_add_chc_to_bd(bin_data, comment);
	token = token->next;
	asm_check_sep(&token);
	asm_check_nl(&token);
}
