/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:53:27 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 23:17:40 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static int		is_big_endian(void)
{
	return (!*(uint8_t *)&(uint16_t){1});
}

static uint32_t	swap_bytes(uint32_t x)
{
	x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
	x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
	return (x);
}

int32_t			convert16(uint16_t x)
{
	if (!is_big_endian())
		x = (x & 0x00FF) << 8 | (x & 0xFF00) >> 8;
	if (x & 32768)
	{
		x = ~x;
		x++;
	}
	return (-(int32_t)x);
}

uint32_t		to_uint32(const uint8_t *mas)
{
	uint32_t	ret;

	ret = *(uint32_t *)mas;
	if (!is_big_endian())
		ret = swap_bytes(ret);
	return (ret);
}
