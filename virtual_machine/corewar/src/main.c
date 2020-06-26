/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:41:56 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/27 01:00:08 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(void)
{
	t_arena	arena;

	arena.cycle = 1;
	arena.cycle_delta = 2;
	arena.cycle_to_die = 3;
	arena.max_checks = 4;
	arena.nbr_live = 5;
	send_arena(&arena);
	return (0);
}
