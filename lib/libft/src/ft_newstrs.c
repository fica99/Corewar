/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:17:01 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/08 22:57:46 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	*ft_newstrs(size_t m_size)
{
	t_string	*new_string;
	char		*str;

	if (!(new_string = (t_string*)malloc(sizeof(t_string))))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (m_size + 1))))
	{
		free(new_string);
		return (NULL);
	}
	*str = '\0';
	new_string->str = str;
	new_string->m_size = m_size;
	new_string->size = 0;
	return (new_string);
}
