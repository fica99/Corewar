#include "corewar.h"

t_cursor	*remove_carriage(t_vm *vm, t_cursor *cursor)
{
	t_cursor 	*tmp;

	vm->num_cursor--;
	tmp = cursor;
	cursor = cursor->next;
	if (vm->prev == NULL)
		vm->cursor = cursor;
	else
		vm->prev->next = cursor;
	if (vm->logs)
		ft_printf("Process %d hasn't lived for %zu cycles (CTD %zd)\n",
				  tmp->id,
				  vm->cycle - tmp->last_live,
				  vm->cycle_to_die);
	free(tmp);
	return (cursor);
}

void		delete_cursor(t_vm *vm)
{
	t_cursor	*cursor;

	vm->prev = NULL;
	cursor = vm->cursor;
	while (cursor)
	{
		if (vm->cycle_to_die <= 0 ||
			vm->cycle - cursor->last_live >= vm->cycle_to_die)
			cursor = remove_carriage(vm, cursor);
		else
		{
			vm->prev = cursor;
			cursor = cursor->next;
		}
	}
}

void		check_map(t_vm *vm)
{
	vm->max_checks++;
	delete_cursor(vm);
	if (vm->max_checks == MAX_CHECKS || vm->nbr_live >= NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		if (vm->logs)
			ft_printf("Cycle to die is now %zd\n", vm->cycle_to_die);
		vm->max_checks = 0;
	}
	vm->nbr_live = 0;
	vm->cycle_after_check = 0;
}
