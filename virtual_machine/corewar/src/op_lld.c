/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:33:21 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:42:08 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int32_t	get_op_arg_lld(t_vm *vm, t_cursor *cursor, int index,
															t_bool mod)
{
	int32_t addr;
	int32_t value;
	t_op	*op;

	op = &g_op[cursor->op_code - 1];
	value = 0;
	if (cursor->args_types[index - 1] & T_REG)
		value = cursor->reg[get_byte(vm, cursor->pc, cursor->step) - 1];
	else if (cursor->args_types[index - 1] & T_DIR)
		value = bytecode_to_int32(vm->arena,
							cursor->pc + cursor->step, op->t_dir_size);
	else if (cursor->args_types[index - 1] & T_IND)
	{
		addr = bytecode_to_int32(vm->arena,
							cursor->pc + cursor->step, IND_SIZE);
		value = bytecode_to_int32(vm->arena,
						cursor->pc + (mod ? (addr % IDX_MOD) : addr), IND_SIZE);
	}
	cursor->step += step_size(cursor->args_types[index - 1], op);
	return (value);
}

void			op_lld(t_vm *vm, t_cursor *cursor)
{
	int32_t		value;
	int32_t		reg;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg_lld(vm, cursor, 1, False);
	cursor->carry = (t_bool)(!value);
	reg = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[reg - 1] = value;
	cursor->step += REG_LEN;
	if (vm->logs)
		ft_printf("P %4d | lld %d r%d\n", cursor->id, value, reg);
}
