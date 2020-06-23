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

int32_t		convert32(uint32_t x)
{
//	if (!is_big_endian())
//		swap_bytes(x);
	if (x & 2147483648)
	{
//		x = ~x;
//		x++;
		x--;
		x++;
	}
	return ((int32_t)x);
}

int32_t		convert16(uint16_t x)
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
