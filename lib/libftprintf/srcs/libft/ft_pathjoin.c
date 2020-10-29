/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:57:29 by mmarti            #+#    #+#             */
/*   Updated: 2020/02/05 14:43:33 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pathjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (0);
	while (*s1)
		str[i++] = *s1++;
	if (*--s1 != '/' && *s2 != '/')
		str[i++] = '/';
	while (*s2)
		str[i++] = *s2++;
	return (str);
}
