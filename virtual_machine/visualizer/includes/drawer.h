/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:12:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/02 22:35:37 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdint>
# include <ncurses.h>
# include <cmath>
# include <limits>

extern "C" {
# include "server.h"
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
# define FT_KEY_ENTER '\n'
# define FT_KEY_SPACE ' '


class Drawer {
public:
	Drawer();
	Drawer(const Drawer &drawer) = delete;
	~Drawer();
	int				getKey(void) const;
	void			changeState(void);
	bool			isRunning(void) const;
	void			drawArena(t_vis_arena &arena);
private:
	bool			_isRunning = true;
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
	void			drawInfo(t_vis_arena &arena);
	void			drawParams(t_vis_arena &arena);
	void			drawMap(t_vis_arena &arena);
	void			drawHelp(void);
	void			drawWinner(t_vis_arena &arena);
	void			drawProgressBar(t_vis_arena &arena, size_t i);
	void			error_print(const char *msg);
	void			initColor(void);
	void			initWindows(void);
};
