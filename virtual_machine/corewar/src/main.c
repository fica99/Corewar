/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:41:56 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/05 02:01:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(void)
{
	t_arena	arena;
	int		listenfd;
	int		i;

	listenfd = connect_to_server();
	i = 0;
	while (i < INT32_MAX / 2) {
		ft_bzero(&arena, sizeof(t_arena));
		arena.cycle = i;
		arena.cycle_delta = rand() % 1000;
		arena.cycle_to_die = rand() % 10000;
		arena.max_checks = rand() % 1000;
		arena.nbr_live = rand() % 100;
		arena.players[0].id = rand() % MAX_PLAYERS + 1;
		arena.players[0].last_live = rand()  % 100000;
		arena.players[0].lives_in_cur_period = rand() % 1000;
		ft_strcpy(arena.players[0].name, "Batman");
		arena.players[1].id = rand() % MAX_PLAYERS + 1;
		arena.players[1].last_live = rand() % 100000;
		arena.players[1].lives_in_cur_period = rand() % 1000;
		ft_strcpy(arena.players[1].name, "Robin");
		arena.players[2].id = rand() % MAX_PLAYERS + 1;
		arena.players[2].last_live = rand() % 100000;
		arena.players[2].lives_in_cur_period = rand() % 1000;
		ft_strcpy(arena.players[2].name, "Superman");
		arena.players[3].id = rand() % MAX_PLAYERS + 1;
		arena.players[3].last_live = rand() % 100000;
		arena.players[3].lives_in_cur_period = rand() % 1000;
		ft_strcpy(arena.players[3].name, "Zorg");
		for (size_t j = 0; j < MEM_SIZE; ++j) {
			arena.arena[j].code = rand() % 256;
			arena.arena[j].player_id = rand() % (MAX_PLAYERS + 1);
		}

		send_arena(&arena, listenfd);
		++i;
	}
	disconnect_from_server(listenfd);
	return (0);
}
