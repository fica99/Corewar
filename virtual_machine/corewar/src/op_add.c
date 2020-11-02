#include "corewar.h"

void	op_add(t_vm *vm, t_cursor *cursor)
{
	int32_t reg_1;
	int32_t reg_2;
	int32_t reg_3;
	int32_t summ;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg_1 = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	reg_2 = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	summ = cursor->reg[reg_1 - 1] + cursor->reg[reg_2 - 1];
	cursor->carry = (t_bool)(!summ);
	reg_3 = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[reg_3 - 1] = summ;
	cursor->step += REG_LEN;
	if (vm->logs)
		ft_printf("P %4d | add r%d r%d r%d\n", cursor->id, reg_1, reg_2, reg_3);
}
