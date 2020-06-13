/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:25:33 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/01 15:48:08 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *append, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (destination[i] != '\0')
		i++;
	j = 0;
	while (j < n && append[j] != '\0')
	{
		destination[i] = append[j];
		j++;
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
