/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:34:38 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:23:18 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_vm *vm, t_cursor *cursor)
{
	int32_t		value;
	int32_t		reg;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, 1, True);
	cursor->carry = (t_bool)(!value);
	reg = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[reg - 1] = value;
	cursor->step += REG_LEN;
	if (vm->logs)
		ft_printf("P %4d | ld %d r%d\n", cursor->id, value, reg);
}
