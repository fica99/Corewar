/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:35:31 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 01:35:31 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t addr;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, True);
	if (cursor->carry)
	{
		cursor->pc = calc_addr(cursor->pc + (addr % IDX_MOD));
		cursor->step = 0;
	}
	if (vm->logs)
		ft_printf("P %4d | zjmp %d %s\n",
					cursor->id,
					addr,
					(cursor->carry) ? "OK" : "FAILED");
}
