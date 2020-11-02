#include "corewar.h"

void	op_ldi(t_vm *vm, t_cursor *cursor)
{
	int32_t addr1;
	int32_t addr2;
	int32_t reg;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	addr1 = get_op_arg(vm, cursor, 1, True);
	addr2 = get_op_arg(vm, cursor, 2, True);
	reg = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[reg - 1] = bytecode_to_int32(vm->arena, (cursor->step + ((addr1 + addr2) % IDX_MOD)), REG_SIZE);
	cursor->step += REG_LEN;
	if (vm->logs)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", cursor->id, addr1, addr2, reg);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				  addr1,
				  addr2,
				  addr1 + addr2,
				  cursor->pc + (addr1 + addr2) % IDX_MOD);
	}
}
