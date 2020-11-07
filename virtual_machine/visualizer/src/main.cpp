/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:25:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/07 16:32:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BACKLOG 5
# include "drawer.h"

using namespace	std;

static KeyHandle	check_key(Drawer& draw) {
	int	key;

	key = draw.getKey();
	if (key == KEY_ESC)
		return KeyHandle::STOP;
	else if (key == FT_KEY_ENTER)
		return KeyHandle::BREAK;
	else if (key == FT_KEY_SPACE) {
		draw.changeState();
		return KeyHandle::DRAW;
	}
	if (draw.isRunning()) {
		if (key == KEY_UP) {
			draw.changeDelay(10ms);
			return KeyHandle::DRAW;
		} else if (key == KEY_DOWN) {
			draw.changeDelay(-10ms);
			return KeyHandle::DRAW;
		}
		if (draw.delay())
			return KeyHandle::CONTINUE;
	} else
		if (key != KEY_RIGHT)
			return KeyHandle::CONTINUE;
	return KeyHandle::RECEIVE_DRAW;
}

static KeyHandle	draw_arena(const int connfd) {
	Drawer			draw;
	KeyHandle		status;
	t_vis_arena		arena;

	flushinp();
	while (true) {
		status = check_key(draw);
		if (status == KeyHandle::CONTINUE)
			continue ;
		else if (status == KeyHandle::DRAW)
			draw.drawArena(arena);
		else if (status == KeyHandle::RECEIVE_DRAW) {
			receive_arena(&arena, connfd);
			draw.drawArena(arena);
		}
		else if (status == KeyHandle::STOP || status == KeyHandle::BREAK)
			break ;
	}
	return (status);
}

static void		server_loop(int listenfd) {
	KeyHandle		status;
	int				connfd;

	while (true) {
		if ((connfd = accept(listenfd, NULL, NULL)) < 0)
			error_message("Accept() failed");
		status = draw_arena(connfd);
		if (close(connfd) < 0)
			error_message("Close() failed");
		if (status == KeyHandle::STOP)
			break ;
	}
}

int		main(void) {
	int	listenfd = create_server();
	if (listen(listenfd, BACKLOG) < 0)
		error_message("Listen() failed");
	server_loop(listenfd);
	if (close(listenfd) < 0)
		error_message("Close() failed");
	return (0);
}
