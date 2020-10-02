/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bin_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:45:09 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/02 16:03:21 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void		asm_bin_data_realoc(t_asm_bin_data *bin_data)
{
	char		*new_data;

	if (!(new_data = (char *)malloc(sizeof(char *)
		* (bin_data->m_size * 2))))
		asm_sys_error();
	ft_memcpy(new_data, bin_data->data, bin_data->size);
	free(bin_data->data);
	bin_data->data = new_data;
	bin_data->m_size *= 2;
}

static void		asm_check_bin_data_size(t_asm_bin_data *bin_data)
{
	if (bin_data->size == bin_data->m_size)
		asm_bin_data_realoc(bin_data);
}

t_asm_bin_data	*asm_init_bin_data(size_t size)
{
	t_asm_bin_data	*bin_data;
	char			*data;

	if (!(bin_data = (t_asm_bin_data *)malloc(sizeof(t_asm_bin_data))))
		asm_sys_error();
	if (!size)
		size = DEFAULT_BIN_DATA_SIZE;
	if (!(data = (char *)malloc(sizeof(char *) * size)))
		asm_sys_error();
	bin_data->data = data;
	bin_data->m_size = size;
	bin_data->size = 0;
	bin_data->check_size = &asm_check_bin_data_size;
	return (bin_data);
}
