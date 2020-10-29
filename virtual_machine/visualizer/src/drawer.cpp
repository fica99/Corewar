/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:14:52 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 18:42:34 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"

using namespace	std;

Drawer::Drawer(void) {
	if (!initscr())
		error_print("Error initialising ncurses");
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(false);
	initColor();
	initWindows();
	drawHelp();
}

Drawer::~Drawer(void) {
	delwin(_map);
	delwin(_info);
	delwin(_params);
	delwin(_help);
	clear();
	echo();
	endwin();
}

void	Drawer::initWindows(void) {
	_map = newwin(ARENA_HEIGHT, ARENA_WIDTH, 0, 0);
	_info = newwin(INFO_HEIGHT, INFO_WIDTH, 0, ARENA_WIDTH);
	_params = newwin(PARAMS_HEIGHT, PARAMS_WIDTH, INFO_HEIGHT, ARENA_WIDTH);
	_help = newwin(HELP_HEIGHT, HELP_WIDTH, INFO_HEIGHT + PARAMS_HEIGHT, ARENA_WIDTH);
	box(_map, 0, 0);
	box(_info, 0, 0);
	box(_params, 0, 0);
	box(_help, 0, 0);
	refresh();
	wrefresh(_map);
	wrefresh(_info);
	wrefresh(_params);
	wrefresh(_help);
}

void	Drawer::initColor(void) {
	start_color();
	if (has_colors() == false)
		error_print("Error - has_colors() failed");
	if (start_color() != OK)
		error_print("Error - has_colors() failed");
	init_pair(EMPTY_CEIL, COLOR_WHITE, COLOR_BLACK);
	init_pair(RED_PLAYER, COLOR_RED, COLOR_BLACK);
	init_pair(BLUE_PLAYER, COLOR_BLUE, COLOR_BLACK);
	init_pair(GREEN_PLAYER, COLOR_GREEN, COLOR_BLACK);
	init_pair(YELLOW_PLAYER, COLOR_YELLOW, COLOR_BLACK);
	init_pair(EMPTY_CARRIAGE, COLOR_BLACK, COLOR_WHITE);
	init_pair(RED_CARRIAGE, COLOR_BLACK, COLOR_RED);
	init_pair(BLUE_CARRIAGE, COLOR_BLACK, COLOR_BLUE);
	init_pair(GREEN_CARRIAGE, COLOR_BLACK, COLOR_GREEN);
	init_pair(YELLOW_CARRIAGE, COLOR_BLACK, COLOR_YELLOW);
}

int		Drawer::getKey(void) const {
	return getch();
}

void	Drawer::drawArena(t_vis_arena &arena) {
	drawWinner(arena);
	drawInfo(arena);
	drawParams(arena);
	drawHelp();
	drawMap(arena);
}

void	Drawer::drawWinner(t_vis_arena &arena) {
	if (arena.winner_id) {
		size_t	i = 0;

		while (i < MAX_PLAYERS) {
			if (arena.winner_id == arena.players[i].id)
				break ;
			++i;
		}
		if (i == MAX_PLAYERS)
			return ;
		attrset(COLOR_PAIR(arena.winner_id));
		mvprintw(ARENA_HEIGHT + 2, ARENA_WIDTH / 2, "%s (Player - %d) has won!!!", arena.players[i].name, arena.winner_id);
		attrset(A_NORMAL);
		refresh();
	}
}


void	Drawer::drawMap(t_vis_arena &arena) {
	size_t	i;
	size_t	j;
	size_t	side = sqrt(MEM_SIZE);

	i = 0;
	while (i < side) {
		j = 0;
		while (j < side) {
			if (arena.arena[(i * side) + j].is_carriage)
				wattrset(_map, COLOR_PAIR(arena.arena[(i * side) + j].player_id + MAX_PLAYERS + 1));
			else
				wattrset(_map, COLOR_PAIR(arena.arena[(i * side) + j].player_id));
			mvwprintw(_map, i + 1, 3 * j + 1, "%02x", arena.arena[(i * side) + j].code);
			wattrset(_map, A_NORMAL);
			++j;
		}
		++i;
	}
	wrefresh(_map);
}

void	Drawer::drawProgressBar(t_vis_arena &arena, size_t i) {
	double	num_of_spaces = arena.players[i].lives_in_cur_period / LEN_PER_SPACE;
	int	num = static_cast<int>(num_of_spaces);

	wattrset(_info, COLOR_PAIR(A_NORMAL));
	if (num > LEN_OF_PROGRESS_BAR)
		num = LEN_OF_PROGRESS_BAR;
	wmove(_info, i * 5 + 9, 0);
	wclrtoeol(_info);
	box(_info, 0, 0);
	wattrset(_info, COLOR_PAIR(arena.players[i].id + MAX_PLAYERS + 1));
	for (int j = 0; j < num; ++j)
		mvwprintw(_info, i * 5 + 9, 6 + j, "\'");
}

void	Drawer::drawInfo(t_vis_arena &arena) {
	mvwprintw(_info, 2, INFO_WIDTH / 2 - 2, "INFO");
	mvwprintw(_info, 4, 4, "Cycle : %7d", arena.cycle);
	size_t i = 0;
	while (i < MAX_PLAYERS) {
		if (arena.players[i].id) {
			wattrset(_info, COLOR_PAIR(arena.players[i].id));
			mvwprintw(_info, i * 5 + 6, 4, "Player - %3d : %s", arena.players[i].id, arena.players[i].name);
			mvwprintw(_info, i * 5 + 7, 6, "Last live - %20d", arena.players[i].last_live);
			mvwprintw(_info, i * 5 + 8, 6, "Lives in current period - %6d", arena.players[i].lives_in_cur_period);
			drawProgressBar(arena, i);
			wattrset(_info, COLOR_PAIR(A_NORMAL));
		}
		++i;
	}
	wrefresh(_info);

}

void	Drawer::drawParams(t_vis_arena &arena) {
	mvwprintw(_params, 2, PARAMS_WIDTH / 2 - 2, "PARAMS");
	mvwprintw(_params, 4, 4, "CYCLE_DELTA : %5d", arena.cycle_delta);
	mvwprintw(_params, 6, 4, "CYCLE_TO_DIE : %5d", arena.cycle_to_die);
	mvwprintw(_params, 8, 4, "NBR_LIVE : %5d", arena.nbr_live);
	mvwprintw(_params, 10, 4, "MAX_CHECKS : %5d", arena.max_checks);
	wrefresh(_params);
}

void	Drawer::drawHelp(void) {
	mvwprintw(_help, 2, HELP_WIDTH / 2 - 2, "HELP");
	mvwprintw(_help, 4, 4, "Key ESC - close server");
	mvwprintw(_help, 6, 4, "Key SPACE - draw next step");
	mvwprintw(_help, 8, 4, "Key ENTER - draw next client");
	wrefresh(_help);
}

void	Drawer::error_print(const char *msg) {
	delwin(_map);
	delwin(_info);
	delwin(_params);
	delwin(_help);
	echo();
	endwin();
	cerr << msg << endl;
	exit(EXIT_FAILURE);
}

