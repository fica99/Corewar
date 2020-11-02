#include "corewar.h"

t_cursor	*copy_cursor(t_cursor *cursor, int32_t addr)
{
	t_cursor	*new;
	int			i;

	i = 0;
	addr = calc_addr(cursor->pc + addr);
	new = init_cursor(cursor->player, addr);
	new->carry = cursor->carry;
	new->last_live = cursor->last_live;
	while (i < REG_NUMBER)
	{
		new->reg[i] = cursor->reg[i];
		i++;
	}
	return (new);
}

void		op_fork(t_vm *vm, t_cursor *cursor)
{
	int32_t		addr;
	t_cursor	*new;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, True);
	new = copy_cursor(cursor, addr % IDX_MOD);
	add_cursor(&(vm->cursor), new);
	vm->num_cursor++;
	if (vm->logs)
		ft_printf("P %4d | fork %d (%d)\n",
				  cursor->id,
				  addr,
				  cursor->pc + addr % IDX_MOD);
}
