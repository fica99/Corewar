/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:35:26 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:35:26 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_xor(t_vm *vm, t_cursor *cursor)
{
	int32_t		value1;
	int32_t		value2;
	int32_t		reg;
	int32_t		result;

	cursor->step += (ARGS_CODE_LEN + OP_CODE_LEN);
	value1 = get_op_arg(vm, cursor, 1, True);
	value2 = get_op_arg(vm, cursor, 2, True);
	result = value1 ^ value2;
	cursor->carry = (t_bool)(!result);
	reg = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[reg - 1] = result;
	cursor->step += REG_LEN;
	if (vm->logs)
		ft_printf("P %4d | xor %d %d r%d\n", cursor->id, value1, value2, reg);
}
