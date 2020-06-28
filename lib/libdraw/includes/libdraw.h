/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:58:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/28 22:08:35 by aashara-         ###   ########.fr       */
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
	const uint16_t	WINDOW_WIDTH = 640;
	const uint16_t	WINDOW_HEIGHT = 640;
	WINDOW			*_win;
};
