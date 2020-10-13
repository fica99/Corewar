/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_obj_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:36:27 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/13 21:56:44 by olegmulko        ###   ########.fr       */
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
	labels->clear = &asm_labels_clear;
	return (labels);
}

size_t			asm_labels_is_contain(t_asm_labels *labels, char *name)
{
	size_t		i;
	t_asm_label	obj_label;

	i = 0;
	if (!labels->size)
		return (0);
	while (i < labels->size)
	{
		obj_label = labels->labels[i];
		if (!ft_strcmp(obj_label.name, name))
			return (obj_label.count);
		i++;
	}
	return (0);
}

int				asm_labels_add(t_asm_labels *labels, char *name)
{
	t_asm_label	obj_label;

	(void)obj_label;
	asm_labels_check_size(labels);
	if (labels->is_contain(labels, name))
		return (0);
	obj_label = labels->labels[labels->size];
	obj_label.name = name;
	return (1);
}

void			asm_labels_clear(t_asm_labels *labels)
{
	size_t		i;
	size_t		size;
	t_asm_label	obj_label;

	(void)obj_label;
	i = 0;
	size = labels->size;

	while (i < size)
	{
		obj_label = labels->labels[i];
		obj_label.name = NULL;
		obj_label.count = 0;
		i++;
	}
}
