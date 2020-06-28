/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:06:42 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/28 22:12:10 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

using namespace	std;

Drawer::Drawer(void) {
	initscr();
	_win = newwin(0, 0, 0, 0);
	noecho();
	halfdelay(1);
}

Drawer::~Drawer(void) {
	delwin(_win);
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
	wprintw(_win,  "Hello World!\n");
	wrefresh(_win);
}
