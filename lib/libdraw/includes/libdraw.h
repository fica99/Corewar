/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:58:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/29 00:30:01 by aashara-         ###   ########.fr       */
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
	const uint16_t	INFO_WIDTH = 20;
	const uint16_t	INFO_HEIGHT = 30;
	uint16_t		SCREEN_WIDTH;
	uint16_t		SCREEN_HEIGHT;
	WINDOW			*_arena;
	WINDOW			*_info;
};
