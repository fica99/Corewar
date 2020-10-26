/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:09:52 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/26 21:16:23 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tcp_socket.h"

static int	get_socket_fd(struct addrinfo *serv_info, struct addrinfo *info)
{
	static struct addrinfo			*p;
	int								socket_fd;

	p = serv_info;
	while (p)
	{
		socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
		if (socket_fd != -1)
		{
			if (connect(socket_fd, p->ai_addr, p->ai_addrlen) == -1)
				close(socket_fd);
			else
				break;
		}
		p = p->ai_next;
	}
	if (!p)
	{
		fprintf(stderr, "Failed to connect\n");//ft_printf
		exit(1);
	}
	info = p;
	return (socket_fd);
}

int	create_server(void)
{
	int				rv;
	struct addrinfo	hints;
	struct addrinfo	*servinfo;

	ft_memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv)); //printf;
		exit(1);
	}

	freeaddrinfo(servinfo);
}

int main(void)
{
int sockfd, new_fd;  // слушаем на sock_fd, новые соединения — на new_fd
struct addrinfo hints, *servinfo, *p;
struct sockaddr_storage their_addr; // информация об адресе клиента
socklen_t sin_size;
struct sigaction sa;
int yes=1;
char s[INET6_ADDRSTRLEN];
int rv;

memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_PASSIVE; // use my IP

if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
fprintf(stderr, «getaddrinfo: %sn», gai_strerror(rv));
return 1;
}

// цикл через все результаты, чтобы забиндиться на первом возможном
for(p = servinfo; p != NULL; p = p->ai_next) {
if ((sockfd = socket(p->ai_family, p->ai_socktype,
p->ai_protocol)) == — 1) {
perror(«server: socket»);
continue;
}

if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
sizeof(int)) == — 1) {
perror(«setsockopt»);
exit(1);
}

if (bind(sockfd, p->ai_addr, p->ai_addrlen) == — 1) {
close(sockfd);
perror(«server: bind»);
continue;
}

break;
}

if (p == NULL)  {
fprintf(stderr, «server: failed to bindn»);
return 2;
}

freeaddrinfo(servinfo); // всё, что можно, с этой структурой мы сделали

if (listen(sockfd, BACKLOG) == — 1) {
perror(«listen»);
exit(1);
}

sa.sa_handler = sigchld_handler; // обрабатываем мёртвые процессы
sigemptyset(&sa.sa_mask);
sa.sa_flags = SA_RESTART;
if (sigaction(SIGCHLD, &sa, NULL) == — 1) {
perror(«sigaction»);
exit(1);
}

printf(«server: waiting for connections...n»);

return 0;
}
