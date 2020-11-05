/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:35:12 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 02:32:12 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	void	st_sti_for_vs(t_vm *vm, t_cursor *cursor,
							int32_t addr, int size)
{
	while (size)
	{
		vm->vs_arena.arena[calc_addr(addr + size - 1)].player_id =
				cursor->player->id;
		size--;
	}
}

void			op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t		reg;
	int32_t		reg_v;
	int32_t		addr;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg = get_byte(vm, cursor->pc, cursor->step);
	reg_v = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	if (cursor->args_types[1] == T_REG)
	{
		addr = get_byte(vm, cursor->pc, cursor->step);
		cursor->reg[addr - 1] = reg_v;
		cursor->step += REG_LEN;
	}
	else
	{
		addr = bytecode_to_int32(vm->arena,
									cursor->pc + cursor->step, IND_SIZE);
		int32_to_bytecode(vm->arena, cursor->pc + (addr % IDX_MOD),
									reg_v, DIR_SIZE);
		st_sti_for_vs(vm, cursor, (cursor->pc + (addr % IDX_MOD)), DIR_SIZE);
		cursor->step += IND_SIZE;
	}
	if (vm->logs)
		ft_printf("P %4d | st r%d %d\n", cursor->id, reg, addr);
}
