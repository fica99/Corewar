/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:25:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/27 21:12:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

using namespace	std;

static void		drawingArena(int connfd) {
	Drawer			draw;
	t_vis_arena		arena;

	while (true) {
		if (!draw.isRunning())
		 	break;
		if (receive_arena(&arena, connfd) < 0)
			continue ;
		draw.drawArena(arena);
	}
}


static void		server_loop(int listenfd) {
	while (true) {
		int connfd = accept(listenfd, NULL, NULL);
		if (connfd < 0)
			error_message("Accept() failed");
		drawingArena(connfd);
		if (close(connfd) < 0)
			error_message("Close() failed");
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
