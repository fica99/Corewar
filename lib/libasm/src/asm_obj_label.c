/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_obj_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:36:27 by olegmulko         #+#    #+#             */
/*   Updated: 2020/11/05 22:52:22 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void		asm_labels_check_size(t_asm_labels *labels)
{
	t_asm_label	*new_objs_label;
	size_t		new_size;

	if (labels->size >= labels->m_size)
	{
		new_size = labels->m_size * 2;
		if (!(new_objs_label = (t_asm_label *)malloc(sizeof(t_asm_label)
			* new_size)))
			asm_sys_error();
		ft_memcpy(new_objs_label, labels->labels, labels->size);
		free(labels->labels);
		labels->labels = new_objs_label;
		labels->m_size = new_size;
	}
}

t_asm_labels	*asm_init_labels(size_t size)
{
	t_asm_labels	*labels;
	t_asm_label		*objs_label;

	if (!(labels = (t_asm_labels *)malloc(sizeof(t_asm_labels))))
		asm_sys_error();
	if (!(objs_label = (t_asm_label *)malloc(sizeof(t_asm_label) * size)))
		asm_sys_error();
	labels->labels = objs_label;
	labels->size = 0;
	labels->m_size = size;
	labels->is_contain = &asm_labels_is_contain;
	labels->add = &asm_labels_add;
	return (labels);
}

int				asm_labels_is_contain(t_asm_labels *labels, char *name)
{
	size_t		i;
	t_asm_label	*obj_label;

	i = 0;
	if (!labels->size)
		return (-1);
	while (i < labels->size)
	{
		obj_label = &labels->labels[i];
		if (!ft_strcmp(obj_label->name, name))
			return (obj_label->count);
		i++;
	}
	return (-1);
}

int				asm_labels_add(t_asm_labels *labels, char *name, int count)
{
	t_asm_label	*obj_label;

	asm_labels_check_size(labels);
	if (labels->is_contain(labels, name) != -1)
		return (0);
	obj_label = &labels->labels[labels->size];
	if (!(obj_label->name = ft_strdup(name)))
		asm_sys_error();
	obj_label->count = count;
	labels->size++;
	return (1);
}
