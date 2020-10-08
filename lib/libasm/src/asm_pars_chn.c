/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_pars_chn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:22:18 by ggrimes           #+#    #+#             */
/*   Updated: 2020/10/08 20:41:07 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	asm_add_chn_to_bd(t_asm_bin_data *bin_data,
	char *name)
{
	size_t	i;

	i = 0;
	while (name[i])
		bin_data->add(bin_data, (int)name[i++], 2);
	while (i < PROG_NAME_LENGTH)
	{
		bin_data->add(bin_data, 0, 2);
		i++;
	}
}

static void	asm_pars_check_chn_token(t_asm_token **token)
{
	if ((*token)->type != TT_CHAMP_NAME)
		asm_prog_error(ERR_PARS_CHAMP_NAME_TOKEN);
	(*token) = (*token)->next;
}

void		asm_pars_champ_name(t_asm_token *token,
	t_asm_bin_data *bin_data)
{
	char	*name;
	size_t	size;

	while (asm_check_sep(&token) || asm_check_nl_in_loop(&token))
		;
	asm_pars_check_chn_token(&token);
	if (token->type != TT_STRING)
		asm_prog_error("parser error");
	name = (char *)token->data;
	if ((size = ft_strlen(name)) > PROG_NAME_LENGTH)
		asm_prog_error(ERR_CHAMP_NAME_LEN);
	asm_add_chn_to_bd(bin_data, name);
	token = token->next;
	asm_check_sep(&token);
	asm_check_nl(&token);
	asm_add_null_in_bd(bin_data, 4);
	asm_exec_code(token, bin_data);
}
