/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmulsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:44:28 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/08 23:19:41 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_string	*ft_strs_realoc(t_string *s_str)
{
	char		*newstr;

	if (!(newstr = (char*)malloc(sizeof(char) * (s_str->m_size * 2 + 1))))
	{
		ft_delstrs(&s_str);
		return (NULL);
	}
	ft_memcpy(newstr, s_str->str, s_str->size + 1);
	free(s_str->str);
	s_str->str = newstr;
	s_str->m_size *= 2;
	return (s_str);
}

static t_string	*ft_sub_in_template(t_string *s_str, char *str)
{
	int			i;

	i = -1;
	while(str[++i])
	{
		if (s_str->size >= s_str->m_size)
			if (!(s_str = ft_strs_realoc(s_str)))
				return (NULL);
		s_str->str[s_str->size++] = str[i];
	}
}

t_string		*ft_strmulsub(char *template, int m_size, ...)
{
	va_list 	sub;
	int			i;
	t_string	*s_str;

	if (!(s_str = ft_newstrs(m_size + 1)))
		return (NULL);
	va_start(sub, m_size);
	i = -1;
	while (template[++i])
	{
		if (template[i] == '?' && template[i + 1] != '?')
			if (!(s_str = ft_sub_in_template(s_str, va_arg(sub, char*))))
				return (NULL);
		if (s_str->size >= s_str->m_size)
			if (!(s_str = ft_strs_realoc(s_str)))
				return (NULL);
		s_str->str[s_str->size++] = template[i];
	}
	s_str->str[s_str->size] = '\0';
	va_end(sub);
	return (s_str);
}
