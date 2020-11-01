#include "corewar.h"

void		set_cycle_to_exec(t_vm *vm, t_cursor *cursor)
{
	cursor->op_code = vm->arena[cursor->pc];
	if (cursor->op_code >= 0x01 && cursor->op_code <= 0x10)
		cursor->cycles_to_exec = g_op[cursor->op_code - 1].cycles;
}

void		op_code_for_cursor(t_vm *vm, t_cursor *cursor)
{
	t_op		*op;
	uint32_t	i;

	if (cursor->cycles_to_exec == 0)
		set_cycle_to_exec(vm, cursor);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
	{
		op = NULL;
		if (cursor->op_code >= 0x01 && cursor->op_code <= 0x10)
			op = &g_op[cursor->op_code - 1];
		if (op)
		{
			parse_types_args(vm, op, cursor);
			if (validate_args_types(cursor, op) && validate_args(vm, cursor, op))
				op->func(vm, cursor);
			else
				cursor->step += calc_step(cursor, op);
			if (cursor->step && vm->logs)
			{
				ft_printf("ADV %d (%0.4p -> %0.4p) ", cursor->step,
						  cursor->pc, cursor->pc + cursor->step);
				i = 0;
				while (i < cursor->step)
				{
					ft_printf("%02x ", vm->arena[(cursor->pc + i)]);
					i++;
				}
				ft_printf("\n");
			}
		}
		else
			cursor->step = ARGS_CODE_LEN;
		move_cursor(vm, cursor);
	}
}



void		exec(t_vm *vm)
{
	t_cursor		*cursor;
	t_vis_arena		vs_arena;

	if (vm->vs)
	{
		ft_printf("DRAW\n");
		ft_bzero(&vs_arena, sizeof(vs_arena));
		add_struct_for_vs(vm, &vs_arena);
		send_arena(&vs_arena, vm->listenfd);
	}
	vm->cycle++;
	vm->cycle_after_check++;
	dump_output(vm);
	if (vm->logs)
		ft_printf("It is now cycle %zd\n", vm->cycle);
	cursor = vm->cursor;
	while (cursor)
	{
		op_code_for_cursor(vm, cursor);
		cursor = cursor->next;
	}
}

void		run_vm(t_vm *vm)
{
	if (vm->vs)
		vm->listenfd = connect_server(vm->vs_ip);
	while (vm->num_cursor)
	{
		exec(vm);
		if (vm->cycle_to_die == vm->cycle_after_check || vm->cycle_to_die <= 0)
			check_map(vm);
	}
	if (vm->vs)
		disconnect_server(vm->listenfd);
}
