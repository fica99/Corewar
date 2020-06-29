/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:58:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/29 19:04:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdint>
# include <ncurses.h>

extern "C" {
# include "libsocket.h"
}

# define KEY_ESC 27
class Drawer {
public:
	Drawer();
	~Drawer();
	bool			isRunning(void) const;
	void			drawArena(t_arena &arena);
private:
	const uint16_t	ARENA_WIDTH = 64 * 2 - 1;
	const uint16_t	ARENA_HEIGHT = 64 * 1;
	const uint16_t	INFO_WIDTH = 44;
	const uint16_t	INFO_HEIGHT = 7 + 4 * MAX_PLAYERS;
	const uint16_t	PARAMS_WIDTH = INFO_WIDTH;
	const uint16_t	PARAMS_HEIGHT = 13;
	const uint16_t	HELP_WIDTH = INFO_WIDTH;
	const uint16_t	HELP_HEIGHT = ARENA_HEIGHT - INFO_HEIGHT - PARAMS_HEIGHT;
	WINDOW			*_arena;
	WINDOW			*_info;
	WINDOW			*_params;
	WINDOW			*_help;
	void			drawInfo(t_arena &arena);
	void			drawParams(t_arena &arena);
	void			drawHelp(void);
};
