/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:58:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/28 19:29:23 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <iostream>
# include <cstdint>
extern "C" {
# include "libsocket.h"
}
class Drawer {
public:
	Drawer();
	~Drawer();
	bool			isRunning(void) const;
	void			drawArena(t_arena &arena);
private:
	const uint16_t	WINDOW_WIDTH = 640;
	const uint16_t	WINDOW_HEIGHT = 480;
	SDL_Window		*_window;
	SDL_Renderer	*_ren;
	TTF_Font		*_font;
};
