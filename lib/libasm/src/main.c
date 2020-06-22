#include "disasm.h"

int		validate_fname(char *fname)
{
	char *ptr;

	if (!(ptr = ft_strrchr(fname, '.')) || ft_strcmp(ptr, ".cor"))
		return (-1);
	return (0);
}

t_buf	*read_file_cor(char *fname)
{
	int		fd;
	size_t	buf_size;
	t_buf	*buf;
	ssize_t	tmp;

	if ((fd = open(fname, O_RDONLY)) < 0)
	{
		file_error(fname, strerror(errno));
		return (NULL);
	}
	buf = (t_buf *)xmalloc(sizeof(t_buf));
	buf_size = BUF_SIZE;
	if (!(buf->bytes = (uint8_t *)malloc(buf_size)))
		fatal_error(strerror(errno));
	while ((tmp = read(fd, buf->bytes, BUF_SIZE)))
	{
		if (tmp < 0)
			fatal_error(strerror(errno));
		buf->size += tmp;
		if ((size_t)tmp == BUF_SIZE)
			if (!(buf->bytes = (uint8_t *)realloc(buf->bytes,
					buf_size += BUF_SIZE)))
				fatal_error(strerror(errno));
	}
	close(fd);
	return (buf);
}

t_champ	*validate_and_parse(char *filename)
{
	t_buf	*buf;
	t_champ	*champ;

	if (validate_fname(filename))
	{
		file_error(filename, "bad extension");
		return (NULL);
	}
	if (!(buf = read_file_cor(filename)))
		return (NULL);
	if (!buf->size || buf->size < PROG_NAME_LENGTH + COMMENT_LENGTH +
	MAGIC_HEADER_SIZE_BYTES + EXEC_CODE_SIZE_BYTES + NULL_RANGE_BYTES * 2)
	{
		free_buf(buf);
		file_error(filename, "wrong count of bytes");
		return (NULL);
	}
	champ = parse_champ(buf);
	free_buf(buf);
	return (champ);
}

//int	main(int ac, char **av)
//{
//	t_champ *champ;
//
//	if (ac < 2)
//		fatal_error("need arguments\n"
//		USAGE);
//	while (*(++av))
//	{
//		if (!(champ = validate_and_parse(*av)))
//			fatal_error("fatal error");
//		disassembly(champ);
//		free_champ(champ);
//	}
//	return (0);
//}
