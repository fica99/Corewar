/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmulsub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:44:28 by olegmulko         #+#    #+#             */
/*   Updated: 2020/07/13 16:48:32 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_size(t_string *s_str)
{
	if (s_str->size >= s_str->m_size)
		if (!ft_strs_realoc(s_str))
			return (0);
	return (1);
}

static int		ft_check_esc(t_string *s_str, char *tmp, int *i)
{
	if (!s_str || !tmp)
		return (0);
	if (tmp[*i] == '?' && tmp[*i + 1] == '?')
	{
		s_str->str[s_str->size++] = '?';
		(*i)++;
		return (1);
	}
	return (0);
}

static t_string	*ft_sub_in_template(t_string *s_str, char *str)
{
	size_t		i;

	if (!str)
		return (s_str);
	i = 0;
	while (str[i])
	{
		if (!ft_check_size(s_str))
			return (NULL);
		s_str->str[s_str->size++] = str[i++];
	}
	return (s_str);
}

t_string		*ft_strmulsub(char *temp, size_t m_size, ...)
{
	va_list		sub;
	int			i;
	t_string	*s_str;

	if (!(s_str = ft_newstrs(m_size)))
		return (NULL);
	va_start(sub, m_size);
	i = -1;
	while (temp[++i])
	{
		if (!ft_check_size(s_str))
			return (NULL);
		if (ft_check_esc(s_str, temp, &i))
			continue;
		if (temp[i] == '?')
		{
			if (!(s_str = ft_sub_in_template(s_str, va_arg(sub, char*))))
				return (NULL);
			continue;
		}
		s_str->str[s_str->size++] = temp[i];
	}
	s_str->str[s_str->size] = '\0';
	va_end(sub);
	return (s_str);
}
