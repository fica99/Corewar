/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:25:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/27 19:01:51 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	main(void) {
	int	socketfd;
	int	new_fd;

	socketfd = create_server();
	if (listen(socketfd, BACKLOG) == -1)
		error_message("listen");

	while(1) {
		new_fd = accept(socketfd, NULL, 0);
		if (new_fd == -1) {
			perror("accept");
			continue;
		}
		
	}
	return (0);
}
