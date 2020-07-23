/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:25:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/23 17:52:16 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static int		initListenFD(void) {
	int					listenfd;
	struct sockaddr_un	srvr_name;

	unlink(SERVER_PATH);
	if ((listenfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
		error_message("socket() failed");
	srvr_name.sun_family = AF_UNIX;
	strncpy(srvr_name.sun_path, SERVER_PATH, sizeof(srvr_name.sun_path) - 1);
	if (bind(listenfd, (struct sockaddr*)&srvr_name, SUN_LEN(&srvr_name)) < 0)
		error_message("bind() failed");
	if (listen(listenfd, 10) < 0)
		error_message("Listen() failed");
	return listenfd;
}

using namespace	std;

static void		drawingArena(int connfd) {
	Drawer		draw;
	t_arena		arena;

	while (true) {
		if (!draw.isRunning())
			break;
		if (receive_arena(&arena, connfd) < 0)
			continue ;
		draw.drawArena(arena);
	}
}


static void		serverLoop(int listenfd) {
	while (true) {
		int connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
		if (connfd < 0)
			error_message("Accept() failed");
		drawingArena(connfd);
		if (close(connfd) < 0)
			error_message("Close() failed");
	}
}

int		main(void) {
	int	listenfd = initListenFD();
	serverLoop(listenfd);
	if (close(listenfd) < 0)
		error_message("Close() failed");
	return (0);
}
