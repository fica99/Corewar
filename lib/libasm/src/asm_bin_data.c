/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bin_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:45:09 by olegmulko         #+#    #+#             */
/*   Updated: 2020/10/02 16:27:08 by olegmulko        ###   ########.fr       */
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

static void		asm_add_bin_data(t_asm_bin_data *bin_data, int data, size_t size)
{
	size_t		i;
	char		byte;

	if (size > 4)
		asm_prog_error(ERR_BIN_DATA_ADD_SIZE);
	i = 0;
	while (i < size)
	{
		byte = data << 8 * i;
		bin_data->check_size(bin_data);
		bin_data->data[bin_data->size] = byte;
		bin_data->size++;
		i++;
	}
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
	bin_data->add = &asm_add_bin_data;
	return (bin_data);
}
