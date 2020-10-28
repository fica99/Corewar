/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:41:50 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/14 09:25:55 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;
	int	res;

	if (s)
	{
		i = ft_strlen(s);
		res = write(fd, s, i);
		if (res == -1)
			return ;
	}
}
