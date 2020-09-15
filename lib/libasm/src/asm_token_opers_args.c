/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_token_opers_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:06:12 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/15 21:41:19 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				asm_check_opers_args(t_asm_string *asm_str)
{
	if (asm_check_arg_reg(asm_str)
		|| asm_check_arg_dir(asm_str))
		return (1);
	return (0);
}
