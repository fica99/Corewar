/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:58:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/15 22:25:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdint>
# include <ncurses.h>
# include <cmath>

extern "C" {
# include "libsocket.h"
}

# define KEY_ESC 27
# define EMPTY_CEIL 0
# define RED_PLAYER 1
# define BLUE_PLAYER 2
# define GREEN_PLAYER 3
# define YELLOW_PLAYER 4
# define EMPTY_CARRIAGE 5
# define RED_CARRIAGE 6
# define BLUE_CARRIAGE 7
# define GREEN_CARRIAGE 8
# define YELLOW_CARRIAGE 9


class Drawer {
public:
	Drawer();
	~Drawer();
	bool			isRunning(void) const;
	void			drawArena(t_arena &arena);
private:
	const uint16_t	ARENA_WIDTH = 64 * 3 + 1;
	const uint16_t	ARENA_HEIGHT = 64 * 1 + 2;
	const uint16_t	INFO_WIDTH = 47;
	const uint16_t	INFO_HEIGHT = 8 + 5 * MAX_PLAYERS;
	const uint16_t	PARAMS_WIDTH = INFO_WIDTH;
	const uint16_t	PARAMS_HEIGHT = 13;
	const uint16_t	HELP_WIDTH = INFO_WIDTH;
	const uint16_t	LEN_OF_PROGRESS_BAR = 32;
	const uint16_t	LEN_PER_SPACE = 10;
	const uint16_t	HELP_HEIGHT = ARENA_HEIGHT - INFO_HEIGHT - PARAMS_HEIGHT;
	WINDOW			*_map;
	WINDOW			*_info;
	WINDOW			*_params;
	WINDOW			*_help;
	void			drawInfo(t_arena &arena);
	void			drawParams(t_arena &arena);
	void			drawMap(t_arena &arena);
	void			drawHelp(void);
	void			drawWinner(t_arena &arena);
	void			drawProgressBar(t_arena &arena, size_t i);
	void			error_print(const char *msg);
	void			initColor(void);
	void			initWindows(void);
};
