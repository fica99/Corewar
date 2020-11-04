/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:35:44 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:45:43 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		parse_types_args(t_vm *vm, t_op *op, t_cursor *cursor)
{
	int8_t args_types_byte;

	args_types_byte = get_byte(vm, cursor->pc, 1);
	if (op->args_types_code)
	{
		if (op->args_num >= 1)
		{
			cursor->args_types[0] = (int8_t)((args_types_byte & 0xC0) >> 6);
			if (cursor->args_types[0] + 1 == T_IND)
				cursor->args_types[0] = T_IND;
		}
		if (op->args_num >= 2)
		{
			cursor->args_types[1] = (int8_t)((args_types_byte & 0x30) >> 4);
			if (cursor->args_types[1] + 1 == T_IND)
				cursor->args_types[1] = T_IND;
		}
		if (op->args_num >= 3)
			cursor->args_types[2] = (int8_t)((args_types_byte & 0xC) >> 2);
	}
	else
		cursor->args_types[0] = op->args_types[0];
}

t_bool		is_register(t_vm *vm, int32_t pc, int32_t step)
{
	int8_t r_id;

	r_id = get_byte(vm, pc, step);
	return (t_bool)(r_id >= 1 && r_id <= REG_NUMBER);
}

t_bool		validate_args(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = (OP_CODE_LEN + (op->args_types_code ? ARGS_CODE_LEN : 0));
	while (i < op->args_num)
	{
		if ((cursor->args_types[i] == T_REG)
			&& !is_register(vm, cursor->pc, step))
			return (False);
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (True);
}

t_bool		val_args_types(t_cursor *cursor, t_op *op)
{
	int i;

	i = 0;
	while (i < op->args_num)
	{
		if (!(cursor->args_types[i] & op->args_types[i]))
			return (False);
		i++;
	}
	return (True);
}
