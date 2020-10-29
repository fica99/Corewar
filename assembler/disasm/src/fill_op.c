/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:53:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 21:58:30 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static void				set_args(t_op *op, uint8_t args_type_code)
{
	op->args_types[0] = (args_type_code >> 6) & TWO_LAST_BITS;
	op->args_types[1] = (args_type_code >> 4) & TWO_LAST_BITS;
	op->args_types[2] = (args_type_code >> 2) & TWO_LAST_BITS;
}

static const uint8_t	*get_arg_val(t_op *op, const uint8_t *bytes)
{
	int i;

	i = 0;
	while (i < op->args_num)
	{
		if (op->args_types[i] == T_REG)
		{
			op->args_val[i] = (int32_t)(*bytes);
			bytes++;
		}
		else if (op->args_types[i] == T_IND ||
		(op->args_types[i] == T_DIR && op->t_dir_size == 2))
		{
			op->args_val[i] = convert16(*(uint16_t *)bytes);
			bytes += 2;
		}
		else
		{
			op->args_val[i] = to_uint32(bytes);
			bytes += 4;
		}
		i++;
	}
	return (bytes);
}

int						fill_op(t_op *op, const uint8_t *bytes)
{
	const uint8_t *old_bytes;

	old_bytes = bytes;
	bytes++;
	if (op->args_types_code)
	{
		set_args(op, *bytes);
		bytes++;
	}
	return ((int)(get_arg_val(op, bytes) - old_bytes));
}
