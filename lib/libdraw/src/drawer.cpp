/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:06:42 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/05 13:32:27 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

using namespace	std;

Drawer::Drawer(void) {
	if (!initscr())
		error_print("Error initialising ncurses");
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	if (has_colors() == false)
		error_print("Error - has_colors() failed");
	if (start_color() != OK)
		error_print("Error - has_colors() failed");
	_map = newwin(ARENA_HEIGHT, ARENA_WIDTH, 0, 0);
	_info = newwin(INFO_HEIGHT, INFO_WIDTH, 0, ARENA_WIDTH);
	_params = newwin(PARAMS_HEIGHT, PARAMS_WIDTH, INFO_HEIGHT, ARENA_WIDTH);
	_help = newwin(HELP_HEIGHT, HELP_WIDTH, INFO_HEIGHT + PARAMS_HEIGHT, ARENA_WIDTH);
	initColor();
	refresh();
	box(_map, 0, 0);
	box(_info, 0, 0);
	box(_params, 0, 0);
	box(_help, 0, 0);
	wrefresh(_map);
	wrefresh(_info);
	wrefresh(_params);
	wrefresh(_help);
}

void	Drawer::initColor(void) {
	init_pair(EMPTY_CEIL, COLOR_BLACK, COLOR_BLACK);
	init_pair(RED_PLAYER, COLOR_RED, COLOR_BLACK);
	init_pair(BLUE_PLAYER, COLOR_BLUE, COLOR_BLACK);
	init_pair(GREEN_PLAYER, COLOR_GREEN, COLOR_BLACK);
	init_pair(YELLOW_PLAYER, COLOR_YELLOW, COLOR_BLACK);
}

Drawer::~Drawer(void) {
	delwin(_map);
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
	drawMap(arena);
	drawInfo(arena);
	drawParams(arena);
	drawHelp();
}

void	Drawer::drawMap(t_arena &arena) {
	size_t	i;
	size_t	j;
	size_t	side = sqrt(MEM_SIZE);

	i = 0;
	while (i < side) {
		j = 0;
		while (j < side) {
			if (arena.arena[(i * side) + j].code)
				wattrset(_map, COLOR_PAIR(arena.arena[(i * side) + j].player_id));
			mvwprintw(_map, i + 1, 3 * j + 1, "%02x", arena.arena[(i * side) + j].code);
			wattrset(_map, A_NORMAL);
			++j;
		}
		++i;
	}
	wrefresh(_map);
}

void	Drawer::drawInfo(t_arena &arena) {
	mvwprintw(_info, 2, INFO_WIDTH / 2 - 2, "INFO");
	mvwprintw(_info, 4, 4, "Cycle : %7d", arena.cycle);
	size_t i = 0;
	while (i < MAX_PLAYERS) {
		if (arena.players[i].id) {
			wattrset(_info, COLOR_PAIR(arena.players[i].id));
			mvwprintw(_info, i * 4 + 6, 4, "Player - %3d : %s", arena.players[i].id, arena.players[i].name);
			mvwprintw(_info, i * 4 + 7, 6, "Last live - %20d", arena.players[i].last_live);
			mvwprintw(_info, i * 4 + 8, 6, "Lives in current period - %6d", arena.players[i].lives_in_cur_period);
			wattrset(_info, COLOR_PAIR(A_NORMAL));
		}
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

void	Drawer::error_print(const char *msg) {
	cerr << msg << endl;
	delwin(_map);
	delwin(_info);
	delwin(_params);
	delwin(_help);
	endwin();
	exit(EXIT_FAILURE);
}
