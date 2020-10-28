/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:25:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 18:41:20 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

using namespace	std;

static int		draw_arena(const int connfd)
{
	Drawer			draw;
	int				key;
	t_vis_arena		arena;

	flushinp();
	while (true) {
		key = draw.getKey();
		if (key == KEY_ESC || key == '\n')
			break ;
		if (key != ' ')
			continue ;
		receive_arena(&arena, connfd);
		draw.drawArena(arena);
	}
	return (key);
}

static void		server_loop(int listenfd) {
	int				key;
	int				connfd;

	while (true) {
		if ((connfd = accept(listenfd, NULL, NULL)) < 0)
			error_message("Accept() failed");
		key = draw_arena(connfd);
		if (close(connfd) < 0)
			error_message("Close() failed");
		if (key == KEY_ESC)
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
