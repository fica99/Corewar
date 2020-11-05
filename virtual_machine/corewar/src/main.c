/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:41:56 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/05 16:39:16 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_cursor(t_cursor **list, t_cursor *new)
{
	if (new)
		new->next = *list;
	*list = new;
}

void	set_cursors(t_vm *vm)
{
	int32_t		i;
	uint32_t	pc;

	i = 0;
	pc = 0;
	while (i < vm->num_players)
	{
		add_cursor(&(vm->cursor), init_cursor(vm->players[i], pc));
		vm->num_cursor++;
		pc += MEM_SIZE / vm->num_players;
		i++;
	}
}

void	player_introduction(t_vm *vm)
{
	int id;

	id = 1;
	ft_printf("Introducing contestants...\n");
	while (id <= vm->num_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				id, vm->players[id - 1]->code_size,
				vm->players[id - 1]->name, vm->players[id - 1]->comment);
		id++;
	}
}

void	free_vm(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < vm->num_players)
	{
		free(vm->players[i]->code);
		free(vm->players[i]);
		free(vm->tmp_players[i]);
		i++;
	}
	free(vm);
}

int		main(int argc, char **argv)
{
	t_vm *vm;

	vm = init_vm();
	argv++;
	argc--;
	if (argc >= 1)
	{
		vm->num_players = check_count_cor_files(argv);
		init_vm_players(vm);
		parse_args(argv, argc, vm);
		init_arena(vm);
		set_cursors(vm);
		player_introduction(vm);
		run_vm(vm);
		ft_printf("Contestant %d, \"%s\", has won !\n",
					vm->last_alive->id, vm->last_alive->name);
	}
	else
		help();
	free_vm(vm);
	return (0);
}
