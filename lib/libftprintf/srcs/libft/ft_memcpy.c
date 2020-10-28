/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:30:34 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/03 21:55:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	unsigned int	i;

	pointer1 = (unsigned char*)dst;
	pointer2 = (unsigned char*)src;
	i = 0;
	if (pointer1 == pointer2 || n == 0)
		return (pointer1);
	while (n > 0)
	{
		pointer1[i] = pointer2[i];
		i++;
		n--;
	}
	return (pointer1);
}
