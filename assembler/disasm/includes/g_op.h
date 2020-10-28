/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_op.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:11:55 by mmarti            #+#    #+#             */
/*   Updated: 2020/10/28 21:58:04 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_OP_H
# define G_OP_H

# include "disasm.h"

static t_op		g_op[OP_COUNT] =
{
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = True,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = True,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.t_dir_size = 2,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = True,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.args_val = {0, 0, 0},
		.next = NULL,
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = True,
		.args_types = {T_REG, 0, 0},
		.t_dir_size = 4,
		.args_val = {0, 0, 0},
		.next = NULL,
	}
};

#endif
