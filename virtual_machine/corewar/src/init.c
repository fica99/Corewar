#include "corewar.h"

t_cursor *init_cursor(t_player *player, int32_t pc)
{
	t_cursor		*cursor;
	static uint32_t id;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		ft_exit("Error malloc");
	cursor->id = ++id;
	cursor->carry = False;
	cursor->op_code = 0;
	cursor->last_live = 0;
	cursor->cycles_to_exec = 0;
	cursor->pc = pc;
	cursor->next = NULL;
	cursor->reg[0] = -(player->id);
	cursor->player = player;
	return (cursor);
}

void	init_arena(t_vm *vm)
{
	int i;
	int prog_count;

	i = 0;
	prog_count = 0;
	while (i < vm->num_players)
	{
		ft_memcpy(&(vm->arena[prog_count]), vm->players[i]->code,
			 vm->players[i]->code_size);
		prog_count += MEM_SIZE / vm->num_players;
		i++;
	}
}

void	init_vm_players(t_vm *vm)
{
	int i;

	i = 0;
	while(i < MAX_PLAYERS)
	{
		if (!(vm->players[i] = (t_player *)malloc(sizeof(t_player))))
			ft_exit("Error malloc");
		i++;
	}
}

t_player	*init_player(int id)
{
	t_player *player;

	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (NULL);
	player->id = id;
	player->last_live = 0;
	player->lives_in_cur_period = 0;
	player->code = NULL;
	ft_bzero(player->name, PROG_NAME_LENGTH);
	ft_bzero(player->comment, COMMENT_LENGTH);
	return (player);
}

t_vm		*init_vm(void)
{
	t_vm *vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		ft_exit("Error VM_INIT");
	vm->num_players = 0;
	vm->last_alive = NULL;
	vm->cursor = NULL;
	vm->num_cursor = 0;
	vm->nbr_live = 0;
	vm->cycle = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->cycle_after_check = 0;
	vm->max_checks = 0;
	vm->dump = -1;
	vm->aff = False;
	vm->logs = False;
	vm->vs = False;
	return (vm);
}
