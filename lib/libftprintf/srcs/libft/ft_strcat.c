/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:36:49 by aashara-          #+#    #+#             */
/*   Updated: 2019/04/09 15:41:22 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *arr)
{
	char	*pointer;
	int		i;
	int		j;

	pointer = destination;
	i = 0;
	if (!arr)
		return (pointer);
	while (pointer[i] != '\0')
		i++;
	j = 0;
	while (arr[j] != '\0')
	{
		pointer[i] = arr[j];
		i++;
		j++;
	}
	pointer[i] = '\0';
	return (pointer);
}
