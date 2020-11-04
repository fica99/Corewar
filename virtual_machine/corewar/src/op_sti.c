/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:35:17 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:39:52 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	void	st_sti_for_vs(t_vm *vm, t_cursor *cursor, int32_t addr,
															int size)
{
	while (size)
	{
		vm->vs_arena.arena[calc_addr(addr + size - 1)].player_id =
				cursor->player->id;
		size--;
	}
}

void			op_sti(t_vm *vm, t_cursor *cursor)
{
	int32_t		reg;
	int32_t		reg_v;
	int32_t		addr1;
	int32_t		addr2;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg = get_byte(vm, cursor->pc, cursor->step);
	reg_v = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	addr1 = get_op_arg(vm, cursor, 2, True);
	addr2 = get_op_arg(vm, cursor, 3, True);
	int32_to_bytecode(vm->arena,
				(cursor->pc + ((addr1 + addr2) % IDX_MOD)), reg_v, DIR_SIZE);
	if (vm->vs)
		st_sti_for_vs(vm, cursor,
				(cursor->pc + ((addr1 + addr2) % IDX_MOD)), DIR_SIZE);
	if (vm->logs)
	{
		ft_printf("P %4d | sti r%d %d %d\n", cursor->id, reg,
													addr1, addr2);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
					addr1, addr2,
					addr1 + addr2, cursor->pc + ((addr1 + addr2) % IDX_MOD));
	}
}
