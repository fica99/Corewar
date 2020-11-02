#include "corewar.h"

void	op_st(t_vm *vm, t_cursor *cursor)
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
		addr = get_op_arg(vm, cursor, 1, True);
		int32_to_bytecode(vm->arena, cursor->pc + (addr % IDX_MOD), reg_v, REG_SIZE);
		cursor->step += IND_SIZE;
	}
	if (vm->logs)
		ft_printf("P %4d | st r%d %d\n", cursor->id, reg, addr);
}
