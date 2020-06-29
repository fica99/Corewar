/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:41:56 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/29 19:08:52 by aashara-         ###   ########.fr       */
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
		arena.cycle = rand() % 100000;
		arena.cycle_delta = rand() % 1000;
		arena.cycle_to_die = rand() % 10000;
		arena.max_checks = rand() % 1000;
		arena.nbr_live = rand() % 100;
		arena.players[0].id = rand() % 256;
		arena.players[0].last_live = rand()  % 100000;
		arena.players[0].lives_in_cur_period = rand() % 10000;
		strcpy(arena.players[0].name, "Batman");
		arena.players[1].id = rand() % 256;
		arena.players[1].last_live = rand() % 100000;
		arena.players[1].lives_in_cur_period = rand() % 1000;
		strcpy(arena.players[1].name, "Robin");
		arena.players[2].id = rand() % 256;
		arena.players[2].last_live = rand() % 100000;
		arena.players[2].lives_in_cur_period = rand() % 1000;
		strcpy(arena.players[2].name, "Superman");
		// arena.players[3].id = rand() % 256;
		// arena.players[3].last_live = rand() % 100000;
		// arena.players[3].lives_in_cur_period = rand() % 1000;
		// strcpy(arena.players[3].name, "Zorg");
		send_arena(&arena, listenfd);
	}
	disconnect_from_server(listenfd);
	return (0);
}
