#include "libdisasm.h"

static char		*get_champ_name(const uint8_t *bytes)
{
	char *ret;

	ret = (char *)xmalloc(PROG_NAME_LENGTH + 1);
	ft_memcpy(ret, bytes + MAGIC_HEADER_SIZE_BYTES, PROG_NAME_LENGTH);
	return (ret);
}

static char		*get_champ_comment(const uint8_t *bytes)
{
	char *ret;

	bytes += MAGIC_HEADER_SIZE_BYTES + NULL_RANGE_BYTES +
			EXEC_CODE_SIZE_BYTES + PROG_NAME_LENGTH;
	ret = (char *)xmalloc(COMMENT_LENGTH + 1);
	ft_memcpy(ret, bytes, COMMENT_LENGTH);
	return (ret);
}

static size_t	get_champ_exec_code_size(const uint8_t *bytes)
{
	bytes += MAGIC_HEADER_SIZE_BYTES + PROG_NAME_LENGTH + NULL_RANGE_BYTES;
	return (to_uint32(bytes));
}

t_op			*get_champ_exec_code(const uint8_t *bytes, size_t esize)
{
	int		op_size;
	t_op	*ret;
	t_op	*tmp;

	bytes += MAGIC_HEADER_SIZE_BYTES + NULL_RANGE_BYTES + EXEC_CODE_SIZE_BYTES +
			PROG_NAME_LENGTH + COMMENT_LENGTH + NULL_RANGE_BYTES;
	ret = NULL;
	while (esize > 0)
	{
		if (!(tmp = op_push_back(&ret, *bytes)))
		{
			free_op_list(ret);
			return (NULL);
		}
		op_size = fill_op(tmp, bytes);
		bytes += op_size;
		esize -= op_size;
	}
	return (ret);
}

t_champ			*parse_champ(t_buf *buf)
{
	t_champ *champ;

	if (to_uint32(buf->bytes) != COREWAR_EXEC_MAGIC)
	{
		ft_putendl_fd("wrong magic number", STDERR_FILENO);
		return (NULL);
	}
	champ = (t_champ *)xmalloc(sizeof(t_champ));
	champ->name = get_champ_name(buf->bytes);
	champ->exec_code_size = get_champ_exec_code_size(buf->bytes);
	champ->comment = get_champ_comment(buf->bytes);
	if (!(champ->exec_code = get_champ_exec_code(buf->bytes,
			champ->exec_code_size)))
	{
		free_champ(champ);
		return (NULL);
	}
	return (champ);
}
