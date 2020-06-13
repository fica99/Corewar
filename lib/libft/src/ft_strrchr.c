/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:45:32 by aashara-          #+#    #+#             */
/*   Updated: 2019/04/04 13:35:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*pointer;
	int		i;

	pointer = (char*)str;
	i = 0;
	while (pointer[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (pointer[i] == ch)
			return (&pointer[i]);
		i--;
	}
	return (NULL);
}
