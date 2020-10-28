/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:17:51 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 20:59:34 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	unsigned int	i;

	pointer1 = (unsigned char*)dst;
	pointer2 = (unsigned char*)src;
	i = 0;
	while (n)
	{
		pointer1[i] = pointer2[i];
		if (pointer1[i] == (unsigned char)c)
			return (pointer1 + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
