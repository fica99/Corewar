/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:08:31 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 22:01:55 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	int				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	pointer1 = (unsigned char*)dst;
	pointer2 = (unsigned char*)src;
	i = -1;
	if (pointer2 < pointer1)
	{
		while ((int)--n >= 0)
			pointer1[n] = pointer2[n];
	}
	else
		while (++i < (int)n)
			pointer1[i] = pointer2[i];
	return (pointer1);
}
