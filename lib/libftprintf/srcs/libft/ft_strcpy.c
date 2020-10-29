/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:01:44 by aashara-          #+#    #+#             */
/*   Updated: 2020/01/20 22:56:44 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destination, const char *source)
{
	int		i;
	char	*pointer1;

	if (!source)
		return (destination);
	i = 0;
	pointer1 = destination;
	while (source[i] != '\0')
	{
		pointer1[i] = source[i];
		i++;
	}
	pointer1[i] = '\0';
	return (pointer1);
}
