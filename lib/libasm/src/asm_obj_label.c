/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_obj_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:36:27 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/13 21:04:52 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

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
	return (labels);
}
