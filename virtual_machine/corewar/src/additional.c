#include "corewar.h"

int32_t	bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size)
{
	int32_t		result;
	t_bool		sign;
	int			i;

	result = 0;
	sign = (t_bool)(arena[calc_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[calc_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[calc_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

void		int32_to_bytecode(uint8_t *arena, int32_t addr, int32_t value,
							  int32_t size)
{
	int8_t i;

	i = 0;
	while (size)
	{
		arena[calc_addr(addr + size - 1)] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

int32_t get_op_arg(t_vm *vm, t_cursor *cursor, int index, t_bool mod)
{
	int32_t addr;
	int32_t value;
	t_op	*op;

	op = &g_op[cursor->op_code - 1];
	value = 0;
	if (cursor->args_types[index - 1] & T_REG)
		value = cursor->reg[get_byte(vm, cursor->pc, cursor->step) - 1];
	else if (cursor->args_types[index - 1] & T_DIR)
		value = bytecode_to_int32(vm->arena, cursor->pc + cursor->step, op->t_dir_size);
	else if (cursor->args_types[index - 1] & T_IND)
	{
		addr = bytecode_to_int32(vm->arena, cursor->pc + cursor->step, IND_SIZE);
		value = bytecode_to_int32(vm->arena, cursor->pc + (mod ? (addr % IDX_MOD) : addr), DIR_SIZE);
	}
	cursor->step += step_size(cursor->args_types[index - 1], op);
	return (value);
}

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		atoi_check_int(const char *str)
{
	int				i;
	long			nbr;
	int				negative;
	int				x;

	i = 0;
	nbr = 0;
	negative = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		   (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	(str[i] == '-') ? negative *= -1 : negative;
	if (str[i] == '-' || str[i] == '+')
		i++;
	x = 0;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + str[i++] - 48;
		if (nbr != 0)
			x++;
	}
	nbr = nbr * negative;
	if (nbr > 2147483647 || nbr < -2147483648 || x > 9 || nbr < 0)
		ft_exit("Error");
	return ((int)nbr);
}

int		is_str_digits(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i++])))
			return (0);
	}
	return (1);
}

int		is_int(char *str)
{
	if (!is_str_digits(str))
		return (0);
	else
		atoi_check_int(str);
	return (1);
}