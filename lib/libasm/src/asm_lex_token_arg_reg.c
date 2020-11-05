/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex_token_arg_reg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:57:39 by ggrimes           #+#    #+#             */
/*   Updated: 2020/11/05 22:31:50 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_lex_is_number(t_asm_string *asm_str, size_t i)
{
	int			n_width;

	if (!(asm_str->str[i] == '-' || ft_isdigit(asm_str->str[i])))
		return (0);
	n_width = 0;
	if (asm_str->str[i] == '-')
	{
		n_width++;
		i++;
	}
	while (ft_isdigit(asm_str->str[i]))
	{
		n_width++;
		i++;
	}
	return (n_width);
}

int				asm_lex_is_arg_reg(t_asm_string *asm_str)
{
	size_t		i;
	size_t		size;

	i = asm_str->index;
	size = 0;
	if (asm_str->str[i++] != 'r')
		return (0);
	while (ft_isdigit(asm_str->str[i]))
	{
		i++;
		size++;
	}
	if (!size || size > REG_WIDTH)
		return (0);
	return (1);
}

int				*asm_lex_get_number(t_asm_string *asm_str)
{
	int			*number;
	int			n_width;

	n_width = asm_lex_is_number(asm_str, asm_str->index);
	if (!(number = (int *)malloc(sizeof(int))))
		asm_sys_error();
	*number = ft_atoi(asm_str->str + asm_str->index);
	asm_str->index += (size_t)n_width;
	asm_str->char_num += (size_t)n_width;
	return (number);
}

t_asm_token		*asm_lex_token_arg_reg(t_asm_string *asm_str)
{
	t_asm_token	*token;

	token = asm_lex_new_token(TT_ARG_REG);
	asm_pos_to_token(asm_str, token);
	asm_str->index++;
	asm_str->char_num++;
	token->data = (void*)asm_lex_get_number(asm_str);
	return (token);
}
