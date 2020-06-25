/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:59:01 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/25 20:59:02 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdisasm.h"
#include "disasm.h"

void	get_out_fname(char *out_file)
{
	char *ptr;

	ptr = ft_strrchr(out_file, '.') + 1;
	*ptr++ = 's';
	ft_memset(ptr, 0, ft_strlen(ptr));
}

void	print_champ_comment(t_champ *ch, int fd)
{
	ft_putstr_fd(COMMENT_CMD_STRING, fd);
	ft_putchar_fd(' ', fd);
	ft_putchar_fd('\"', fd);
	ft_putstr_fd(ch->comment, fd);
	ft_putchar_fd('\"', fd);
	ft_putstr_fd("\n\n", fd);
}

void	print_champ_name(t_champ *ch, int fd)
{
	ft_putstr_fd(NAME_CMD_STRING, fd);
	ft_putchar_fd(' ', fd);
	ft_putchar_fd('\"', fd);
	ft_putstr_fd(ch->name, fd);
	ft_putchar_fd('\"', fd);
	ft_putchar_fd('\n', fd);
}

void	print_champ(const char *fname, t_champ *ch)
{
	char	out_file[ft_strlen(fname)];
	int		fd;
	t_op	*op;

	ft_strcpy(out_file, fname);
	get_out_fname(out_file);
	ft_putstr("Writing output program to ");
	ft_putendl(out_file);
	if ((fd = open(out_file, O_CREAT | O_RDWR | O_TRUNC,
			S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP)) < 0)
		fatal_error(strerror(errno));
	print_champ_name(ch, fd);
	print_champ_comment(ch, fd);
	op = ch->exec_code;
	while (op)
	{
		print_op(op, fd);
		ft_putchar_fd('\n', fd);
		op = op->next;
	}
}

int		main(int ac, char **av)
{
	t_champ *champ;

	if (ac < 2)
		fatal_error("argument required\n"
		DISASM_USAGE);
	while (*(++av))
	{
		champ = validate_and_parse(*av);
		if (champ)
		{
			print_champ(*av, champ);
			free_champ(champ);
		}
	}
	return (0);
}
