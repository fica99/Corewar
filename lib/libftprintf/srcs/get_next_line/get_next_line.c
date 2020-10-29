/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:08:38 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/18 20:58:08 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list			*get_buflist(const int fd, t_list **list)
{
	t_list				*plist;

	plist = *list;
	while (plist)
	{
		if (plist->content_size == (size_t)fd)
			return (plist);
		plist = plist->next;
	}
	if (!(plist = ft_lstnew(NULL, 0)))
		return (NULL);
	if (!(plist->content = ft_strnew(0)))
	{
		free(plist);
		return (NULL);
	}
	plist->content_size = (size_t)fd;
	ft_lstadd(list, plist);
	return (plist);
}

static int				read_line(char **buf, int fd)
{
	int					readbytes;
	char				*copy_buf;
	char				*readbuf;

	if (!(readbuf = ft_strnew(GNL_BUFF_SIZE)))
		return (-1);
	while ((readbytes = read(fd, readbuf, GNL_BUFF_SIZE)))
	{
		if (readbytes == -1)
			return (-1);
		readbuf[readbytes] = '\0';
		if (!(copy_buf = ft_strjoin(*buf, readbuf)))
			return (-1);
		free(*buf);
		*buf = copy_buf;
		if (ft_strchr(readbuf, 10))
			break ;
	}
	free(readbuf);
	return (readbytes);
}

static char				*get_line(char **buf, char *pos_chr)
{
	char				*copy_buf;
	char				*line;

	if (pos_chr)
		*pos_chr = '\0';
	if (!(line = ft_strdup(*buf)))
		return (NULL);
	if (!(copy_buf = ft_strdup(!pos_chr ? ft_strchr(*buf, 0) : pos_chr + 1)))
	{
		free(line);
		return (NULL);
	}
	free(*buf);
	*buf = copy_buf;
	return (line);
}

int						get_next_line(const int fd, char **line)
{
	static t_list		*list;
	t_list				*buflist;
	char				*pos_chr;
	int					fr;

	if (fd == -1)
		return (-1);
	buflist = get_buflist(fd, &list);
	if ((pos_chr = ft_strchr((char *)buflist->content, 10)))
	{
		if (!(*line = get_line((char **)&(buflist->content), pos_chr)))
			return (-1);
		return (1);
	}
	if ((fr = read_line((char **)&(buflist->content), fd)) == -1)
		return (-1);
	if (!*((char *)buflist->content) && !fr)
		return (0);
	if (!(*line = get_line((char **)&(buflist->content),
					ft_strchr((char *)buflist->content, 10))))
		return (-1);
	return (1);
}
