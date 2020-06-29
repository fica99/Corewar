/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:06:42 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/29 19:05:23 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

using namespace	std;

Drawer::Drawer(void) {
	if (!initscr()) {
		cerr << "Error initialising ncurses." << endl;
		exit(EXIT_FAILURE);
	}
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	_arena = newwin(ARENA_HEIGHT, ARENA_WIDTH, 0, 0);
	_info = newwin(INFO_HEIGHT, INFO_WIDTH, 0, ARENA_WIDTH - 1);
	_params = newwin(PARAMS_HEIGHT, PARAMS_WIDTH, INFO_HEIGHT - 1, ARENA_WIDTH - 1);
	_help = newwin(HELP_HEIGHT, HELP_WIDTH, INFO_HEIGHT + PARAMS_HEIGHT - 2, ARENA_WIDTH - 1);
	refresh();
	box(_arena, 0, 0);
	box(_info, 0, 0);
	box(_params, 0, 0);
	box(_help, 0, 0);
	wrefresh(_arena);
	wrefresh(_info);
	wrefresh(_params);
	wrefresh(_help);
}

Drawer::~Drawer(void) {
	delwin(_arena);
	delwin(_info);
	delwin(_params);
	delwin(_help);
	endwin();
}

bool	Drawer::isRunning(void) const {
	int ch = getch();
	if (ch == KEY_ESC)
		return false;
	return true;
}

void	Drawer::drawArena(t_arena &arena) {
	drawInfo(arena);
	drawParams(arena);
	drawHelp();
}

void	Drawer::drawInfo(t_arena &arena) {
	mvwprintw(_info, 2, INFO_WIDTH / 2 - 2, "INFO");
	mvwprintw(_info, 4, 4, "Cycle : %7d", arena.cycle);
	size_t i = 0;
	while (arena.players[i].id != 0) {
		mvwprintw(_info, i * 4 + 6, 4, "Player - %3d : %s", arena.players[i].id, arena.players[i].name);
		mvwprintw(_info, i * 4 + 7, 6, "Last live - %20d", arena.players[i].last_live);
		mvwprintw(_info, i * 4 + 8, 6, "Lives in current period - %6d", arena.players[i].lives_in_cur_period);
		++i;
	}
	wrefresh(_info);

}

void	Drawer::drawParams(t_arena &arena) {
	mvwprintw(_params, 2, PARAMS_WIDTH / 2 - 2, "PARAMS");
	mvwprintw(_params, 4, 4, "CYCLE_DELTA : %5d", arena.cycle_delta);
	mvwprintw(_params, 6, 4, "CYCLE_TO_DIE : %5d", arena.cycle_to_die);
	mvwprintw(_params, 8, 4, "NBR_LIVE : %5d", arena.nbr_live);
	mvwprintw(_params, 10, 4, "MAX_CHECKS : %5d", arena.max_checks);
	wrefresh(_params);
}

void	Drawer::drawHelp(void) {
	mvwprintw(_help, 2, HELP_WIDTH / 2 - 2, "HELP");
	mvwprintw(_help, 4, 4, "Key Esc - break connection with client");
	wrefresh(_help);
}
