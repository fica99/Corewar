/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:44:32 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 18:37:21 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *s)
{
	size_t			*iter;
	unsigned char	*end;

	if (!s)
		return (0);
	end = (unsigned char *)s;
	while ((size_t)end % sizeof(size_t))
		if (!(*end++))
			return (end - (unsigned char *)s - 1);
	iter = (size_t *)end;
	while (((*iter - 0x0101010101010101) & ~(*iter) & 0x8080808080808080) == 0)
		iter++;
	end = (unsigned char *)iter;
	while (*end)
		++end;
	return (end - (unsigned char *)s);
}
