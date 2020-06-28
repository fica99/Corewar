/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:06:42 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/28 19:39:42 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

using namespace	std;

Drawer::Drawer(void) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		cerr << "SDL_Init failed: " << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}
	TTF_Init();
	_window = SDL_CreateWindow("Corewar",SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (_window == nullptr) {
		cerr << "SDL_CreateWindow failed: " << SDL_GetError() << endl;
		exit(EXIT_FAILURE);
	}
	_ren = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (_ren == nullptr) {
		cout << "SDL_CreateRender failed: " << SDL_GetError() <<endl;
		exit(EXIT_FAILURE);
	}
	_font = TTF_OpenFont("arial.ttf", 25);
}

Drawer::~Drawer(void) {
	TTF_CloseFont(_font);
	SDL_DestroyRenderer(_ren);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	SDL_Quit();
}

bool	Drawer::isRunning(void) const {
	SDL_Event		e;
	bool			run;

	run = true;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT)
			run = false;
		else if (e.type == SDL_KEYDOWN)
			if (e.key.keysym.sym == SDLK_ESCAPE)
				run = false;
	}
	return run;
}

void	Drawer::drawArena(t_arena &arena) {
	// SDL_Rect arena_rect = {0, 0, 3 * WINDOW_WIDTH / 4, WINDOW_HEIGHT};
	// SDL_Rect info_rect = {3 * WINDOW_WIDTH / 4, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
	// SDL_RenderSetViewport(_ren, &arena_rect);
	// SDL_RenderSetViewport(_ren, &info_rect);
	SDL_Color color = { 255, 255, 255, 0 };
	SDL_Surface * surface = TTF_RenderText_Solid(_font,
	"Welcome to Gigi Labs", color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(_ren, surface);
	SDL_RenderCopy(_ren, texture, NULL, NULL);
	SDL_RenderPresent(_ren);
	SDL_Delay(10000);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	cout << arena.cycle << endl;
}
