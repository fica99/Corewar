/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:44:34 by aashara-          #+#    #+#             */
/*   Updated: 2019/04/30 17:16:51 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*pointer;
	int		i;

	i = 0;
	pointer = (char*)str;
	while (pointer[i] != '\0')
	{
		if (pointer[i] == ch)
			return (&pointer[i]);
		i++;
	}
	if (ch == '\0')
		return (&pointer[i]);
	return (NULL);
}
