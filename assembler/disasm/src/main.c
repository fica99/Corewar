#include "libdisasm.h"

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
	ft_putendl_fd(ch->comment, fd);
	ft_putchar_fd('\n', fd);
}

void	print_champ_name(t_champ *ch, int fd)
{
	ft_putstr_fd(NAME_CMD_STRING, fd);
	ft_putchar_fd(' ', fd);
	ft_putendl_fd(ch->name, fd);
}

char	op_sym(uint8_t op_type)
{
	if (op_type == T_DIR)
		return '%';
	else if (op_type == T_REG)
		return 'r';
	return 0;
}

void	print_op(t_op_list *op, int fd)
{
	int i;
	t_bool first;

	first = true;
	i = 0;
	ft_putstr_fd(op->operation.name, fd);
	ft_putchar_fd(' ', fd);
	while (i < op->operation.args_num)
	{
		if (!first)
			ft_putstr_fd(", ", fd);
		first = false;
		ft_putchar_fd(op_sym(op->operation.args_types[i]), fd);
		ft_putnbr_fd((int)op->args_val[i], fd);
		i++;
	}
}

void	print_champ(const char *fname, t_champ *ch)
{
	char out_file[ft_strlen(fname)];
	int fd;
	t_op_list *op;

	ft_memcpy(out_file, fname, ft_strlen(fname));
	get_out_fname(out_file);
	if ((fd = open(out_file, O_CREAT | O_RDWR | O_TRUNC, S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP)) < 0)
		perror("disasm: ");
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

int main(int ac, char **av)
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
