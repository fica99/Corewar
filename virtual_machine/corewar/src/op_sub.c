#include "corewar.h"

void	op_sub(t_vm *vm, t_cursor *cursor)
{
	int32_t		reg1;
	int32_t		reg2;
	int32_t		reg3;
	int32_t		value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg1 = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	reg2 = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	reg3 = get_byte(vm, cursor->pc, cursor->step);
	cursor->step += REG_LEN;
	value = cursor->reg[reg1 - 1] + cursor->reg[reg2 - 1];
	cursor->carry = (t_bool)(!value);
	cursor->reg[reg3 - 1] = value;
	if (vm->logs)
		ft_printf("P %4d | sub r%d r%d r%d\n", cursor->id, reg1, reg2, reg3);
}
