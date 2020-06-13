/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:48:55 by aashara-          #+#    #+#             */
/*   Updated: 2018/12/04 12:01:46 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_mem(t_list *start, t_list *end)
{
	while (start->next != end)
	{
		start->content = NULL;
		free(start->content);
		start->content_size = 0;
		free(start);
		start = start->next;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*list1;

	if (lst && f)
	{
		list1 = f(lst);
		list = list1;
		while (lst->next != NULL)
		{
			lst = lst->next;
			if (!(list1->next = f(lst)))
			{
				free_mem(list, list1->next);
				return (NULL);
			}
			list1 = list1->next;
		}
		return (list);
	}
	return (NULL);
}
