#include "disasm.h"

void	*xmalloc(size_t size)
{
	void *ptr;

	if (!(ptr = ft_memalloc(size)))
	{
		perror("malloc");
		exit(errno);
	}
	return (ptr);
}

void	free_buf(t_buf *buf)
{
	free(buf->bytes);
	free(buf);
}

void	free_champ(t_champ *champ)
{
	free(champ->name);
	free(champ->comment);
	free(champ->exec_code);
}

int validate_fname(char *fname)
{
	char *ptr;

	if (!(ptr = ft_strrchr(fname, '.')) || ft_strcmp(ptr, ".cor"))
		return (-1);
	return (0);
}

t_buf *read_file(char *fname)
{
	int fd;
	size_t buf_size;
	t_buf *buf;
	ssize_t tmp;

	buf = (t_buf *)xmalloc(sizeof(t_buf));
	if ((fd = open(fname, O_RDONLY)) < 0)
		fatal_error(strerror(errno));
	buf_size = BUF_SIZE;
	if (!(buf->bytes = (uint8_t *)malloc(buf_size)))
		fatal_error(strerror(errno));
	while ((tmp = read(fd, buf->bytes, BUF_SIZE)))
	{
		if (tmp < 0)
			fatal_error(strerror(errno));
		buf->size += tmp;
		if ((size_t)tmp == BUF_SIZE)
		{
			if (!(buf->bytes = (uint8_t *)realloc(buf->bytes, buf_size += BUF_SIZE)))
				fatal_error(strerror(errno));
		}
	}
	return buf;
}

unsigned char	*get_champ_name(uint8_t *bytes)
{
	unsigned char *ret;

	ret = (unsigned char *)xmalloc(PROG_NAME_LENGTH + 1);
	ft_memcpy(ret, bytes + MAGIC_HEADER_SIZE_BYTES, PROG_NAME_LENGTH);
	return (ret);
}

unsigned char *get_champ_comment(uint8_t *bytes)
{
	unsigned char *ret;

	bytes += MAGIC_HEADER_SIZE_BYTES + NULL_RANGE_BYTES + EXEC_CODE_SIZE_BYTES + PROG_NAME_LENGTH;
	ret = (unsigned char *)xmalloc(COMMENT_LENGTH + 1);
	ft_memcpy(ret, bytes, COMMENT_LENGTH);
	return (ret);
}

int		is_big_endian()
{
	return (!*(uint8_t *)&(uint16_t){1});
}

uint32_t swap_bytes(uint32_t x)
{
	x = (x & 0x00FF00FF) <<  8 | (x & 0xFF00FF00) >>  8;
	x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
	return (x);
}

size_t get_champ_exec_code_size(uint8_t *bytes)
{
	bytes += MAGIC_HEADER_SIZE_BYTES + PROG_NAME_LENGTH + NULL_RANGE_BYTES;

	size_t ret = *(size_t *)bytes;
	if (!is_big_endian())
		ret = swap_bytes(ret);
	return (ret);
}

uint32_t to_uint32(uint8_t *mas)
{
	uint32_t ret;

	ret = *(uint32_t *)mas;
	if (!is_big_endian())
		ret = swap_bytes(ret);
	return ret;
}

t_champ 	*fill_champ(t_buf *buf)
{
	t_champ *champ;

	if (to_uint32(buf->bytes) != COREWAR_EXEC_MAGIC)
		return (NULL);
	champ = (t_champ *)xmalloc(sizeof(t_champ));
	champ->name = get_champ_name(buf->bytes);
	champ->exec_code_size = get_champ_exec_code_size(buf->bytes);
	champ->comment = get_champ_comment(buf->bytes);
	//champ->exec_code = get_champ_exec_code(buf->bytes);	//todo
	return (champ);
}

t_champ *validate(char *filename)
{
	t_buf	*buf;
	t_champ	*champ;

	if (validate_fname(filename))
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putendl_fd(": Bad extension", STDERR_FILENO);
		return (NULL);
	}
	buf = read_file(filename);
	if (buf->size < PROG_NAME_LENGTH + COMMENT_LENGTH +
	MAGIC_HEADER_SIZE_BYTES + EXEC_CODE_SIZE_BYTES + NULL_RANGE_BYTES * 2)
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putendl_fd(": wrong count of bytes", STDERR_FILENO);
		return (NULL);
	}
	if (!(champ = fill_champ(buf)))
	{
		ft_putstr_fd(filename, STDERR_FILENO);
		ft_putendl_fd(": wrong magic number", STDERR_FILENO);
	}
	free_buf(buf);
	return (champ);
}

void disassembly(t_champ *champ)
{
	(void)champ;
}

int	main(int ac, char **av)
{
	t_champ *champ;

	if (ac < 2)
		fatal_error("need arguments\n"
		USAGE);
	while (*(++av))
	{
		if (!(champ = validate(*av)))
			fatal_error(NULL);
		disassembly(champ);
		free_champ(champ);
	}
	return 0;
}
