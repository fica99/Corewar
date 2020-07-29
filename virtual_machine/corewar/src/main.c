/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:41:56 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/29 14:18:19 by aashara-         ###   ########.fr       */
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
	ft_bzero((void*)&arena, sizeof(t_arena));
	arena.cycle_delta = rand() % 1000;
	arena.cycle_to_die = rand() % 10000;
	arena.max_checks = rand() % 1000;
	arena.nbr_live = rand() % 100;
	arena.players[0].id = 1;
	arena.players[1].id = 2;
	arena.players[2].id = 3;
	arena.players[3].id = 4;
	while (i < 100) {
		arena.cycle = i;
		arena.players[0].last_live = rand()  % 100000;
		arena.players[0].lives_in_cur_period = rand() % 1000;
		ft_strcpy(arena.players[0].name, "Batman");
		arena.players[1].last_live = rand() % 100000;
		arena.players[1].lives_in_cur_period = rand() % 1000;
		ft_strcpy(arena.players[1].name, "Robin");
		arena.players[2].last_live = rand() % 100000;
		arena.players[2].lives_in_cur_period = rand() % 1000;
		ft_strcpy(arena.players[2].name, "Superman");
		arena.players[3].last_live = rand() % 100000;
		arena.players[3].lives_in_cur_period = rand() % 500;
		ft_strcpy(arena.players[3].name, "Zorg");
		for (size_t j = 0; j < MEM_SIZE / 8; ++j) {
			arena.arena[j].is_carriage = (t_bool)(rand() % 2);
			arena.arena[j].code = rand() % 256;
			arena.arena[j].player_id = 1;
		}
		for (size_t j = MEM_SIZE / 4; j < 3 * MEM_SIZE / 8; ++j) {
			arena.arena[j].is_carriage = (t_bool)(rand() % 2);
			arena.arena[j].code = rand() % 256;
			arena.arena[j].player_id = 2;
		}
		for (size_t j = MEM_SIZE / 2; j < 5 * MEM_SIZE / 8; ++j) {
			arena.arena[j].is_carriage = (t_bool)(rand() % 2);
			arena.arena[j].code = rand() % 256;
			arena.arena[j].player_id = 3;
		}
		for (size_t j = 6 * MEM_SIZE / 8; j < 7 * MEM_SIZE / 8; ++j) {
			arena.arena[j].is_carriage = (t_bool)(rand() % 2);
			arena.arena[j].code = rand() % 256;
			arena.arena[j].player_id = 4;
		}
		if (i == 99)
			arena.winner_id = rand() % 4 + 1;
		send_arena(&arena, listenfd);
		++i;
	}
	disconnect_from_server(listenfd);
	return (0);
}
