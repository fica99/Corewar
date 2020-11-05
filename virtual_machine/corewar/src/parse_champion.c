/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:33:01 by kdeloise          #+#    #+#             */
/*   Updated: 2020/11/05 16:56:17 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t		u_int8_to_u_int32(const u_int8_t *bytecode, int size)
{
	int32_t	result;
	t_bool	sign;
	int		i;

	result = 0;
	sign = (t_bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int32_t		check_reg_size(int fd)
{
	uint8_t buf[4];
	int		num_bytes;

	num_bytes = read(fd, buf, REG_SIZE);
	if (num_bytes < 0)
		ft_exit("Can't read .cor file\n");
	if (num_bytes < 4)
		ft_exit("Invalid bytecode");
	return (u_int8_to_u_int32(buf, REG_SIZE));
}

char		*parse_str(int fd, int len)
{
	char	*buf;
	int		size;

	buf = ft_strnew(len);
	size = read(fd, buf, len);
	if (size != len)
		ft_exit("Error PROG_NAME_LENGTH");
	return (buf);
}

uint8_t		*parse_code(int fd, int code_size)
{
	uint8_t *buf;
	int		size;

	buf = (uint8_t *)malloc(code_size);
	size = read(fd, buf, code_size);
	if (size != code_size)
		ft_exit("Error CODE_SIZE");
	return (buf);
}

t_player	*parse_champion(char *cor_file, t_vm *vm, int id)
{
	t_player	*player;
	int			fd;

	vm = NULL;
	player = init_player(id);
	fd = open(cor_file, O_RDONLY);
	if (fd < 0)
		ft_exit("Can't open .cor file\n");
	if (check_reg_size(fd) != COREWAR_EXEC_MAGIC)
		ft_exit("Invalid magic header\n");
	copy_name(player, fd);
	if (check_reg_size(fd) != 0)
		ft_exit("Reg is not MULL\n");
	if ((player->code_size = check_reg_size(fd)) < 0 ||
		player->code_size > CHAMP_MAX_SIZE)
		ft_exit("Size of champion error\n");
	copy_comment(player, fd);
	if (check_reg_size(fd) != 0)
		ft_exit("\n");
	player->code = parse_code(fd, player->code_size);
	close(fd);
	return (player);
}
