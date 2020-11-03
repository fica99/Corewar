/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlstrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:41:48 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/02 22:13:05 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strs_realoc(t_string *s_str)
{
	char	*newstr;

	if (!(newstr = (char*)malloc(sizeof(char) * (s_str->m_size * 2 + 1))))
	{
		ft_delstrs(&s_str);
		return (0);
	}
	ft_memcpy(newstr, s_str->str, s_str->size + 1);
	free(s_str->str);
	s_str->str = newstr;
	s_str->m_size *= 2;
	return (1);
}
