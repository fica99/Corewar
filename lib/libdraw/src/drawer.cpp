/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:06:42 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/29 00:27:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

using namespace	std;

Drawer::Drawer(void) {
	if (!initscr()) {
		cerr << "Error initialising ncurses." << endl;
		exit(EXIT_FAILURE);
	}
	getmaxyx(stdscr, SCREEN_HEIGHT, SCREEN_WIDTH);
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	_arena = newwin(ARENA_HEIGHT, ARENA_WIDTH, 0, 0);
	_info = newwin(INFO_HEIGHT, INFO_WIDTH, 0, ARENA_WIDTH);
	refresh();
	box(_arena, 0, 0);
	box(_info, 0, 0);
	wrefresh(_arena);
	wrefresh(_info);
}

Drawer::~Drawer(void) {
	delwin(_arena);
	delwin(_info);
	endwin();
}

bool	Drawer::isRunning(void) const {
	int ch = getch();
	if (ch == KEY_ESC)
		return false;
	return true;
}

void	Drawer::drawArena(t_arena &arena) {
	(void)arena;

}
