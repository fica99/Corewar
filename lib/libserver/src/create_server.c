/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:09:52 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/27 21:06:00 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	create_server(void)
{
	int				rv;
	struct addrinfo	hints;
	struct addrinfo	*serv_info;
	struct addrinfo	*info;
	int				fd;

	ft_memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((rv = getaddrinfo(NULL, PORT, &hints, &serv_info)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv)); //printf;
		exit(1);
	}
	fd = get_socket_fd(serv_info, &info);
	rv = 1;
	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &rv, sizeof(int)) == -1)
		error_message("setsockopt");
	while (bind(fd, info->ai_addr, info->ai_addrlen) == -1)
	{
		close(fd);
		fd = get_socket_fd(info->ai_next, &info);
	}
	freeaddrinfo(serv_info);
	return (fd);
}
