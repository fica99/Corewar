/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:09:52 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 21:54:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

struct addrinfo	*get_addr_info(void)
{
	struct addrinfo	hints;
	struct addrinfo	*serv_info;
	int				rv;

	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((rv = getaddrinfo(NULL, PORT, &hints, &serv_info)) != 0)
	{
		ft_dprintf(STDERR_FILENO, "getaddrinfo: %s\n", gai_strerror(rv));
		exit(1);
	}
	return (serv_info);
}

int				create_server(void)
{
	int				rv;
	struct addrinfo	*info;
	struct addrinfo	*serv_info;
	int				fd;

	serv_info = get_addr_info();
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
