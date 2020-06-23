#include "libdisasm.h"
#include "g_op.h"

static char	*get_champ_name(const uint8_t *bytes)
{
	char *ret;

	ret = (char *)xmalloc(PROG_NAME_LENGTH + 1);
	ft_memcpy(ret, bytes + MAGIC_HEADER_SIZE_BYTES, PROG_NAME_LENGTH);
	return (ret);
}

static char *get_champ_comment(const uint8_t *bytes)
{
	char *ret;

	bytes += MAGIC_HEADER_SIZE_BYTES + NULL_RANGE_BYTES + EXEC_CODE_SIZE_BYTES + PROG_NAME_LENGTH;
	ret = (char *)xmalloc(COMMENT_LENGTH + 1);
	ft_memcpy(ret, bytes, COMMENT_LENGTH);
	return (ret);
}

static size_t get_champ_exec_code_size(const uint8_t *bytes)
{
	bytes += MAGIC_HEADER_SIZE_BYTES + PROG_NAME_LENGTH + NULL_RANGE_BYTES;

	return to_uint32(bytes);
}

t_op	*op_list_new(uint8_t byte)
{
	t_op *new;

	new = xmalloc(sizeof(t_op));
	*new = g_op[byte - 1];
	return (new);
}

t_op	*op_push_back(t_op **lst, uint8_t byte)
{
	t_op *tmp;

	if (byte > OP_COUNT)
	{
		ft_putendl_fd("bad operation code", STDERR_FILENO);
		return (NULL);
	}
	tmp = *lst;
	if (!(*lst))
		return (*lst = op_list_new(byte));
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->next = op_list_new(byte));
}

void	set_args(t_op *op, uint8_t args_type_code)
{
	op->args_types[0] = (args_type_code >> 6) & TWO_LAST_BITS;
	op->args_types[1] = (args_type_code >> 4) & TWO_LAST_BITS;
	op->args_types[2] = (args_type_code >> 2) & TWO_LAST_BITS;
}

const uint8_t	*get_arg_val(t_op *op, const uint8_t *bytes)
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

int fill_op(t_op *op, const uint8_t *bytes)
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

t_op *get_champ_exec_code(const uint8_t *bytes, size_t esize)
{
	int 		op_size;
	t_op	*ret;
	t_op	*tmp;

	bytes += MAGIC_HEADER_SIZE_BYTES + NULL_RANGE_BYTES +
			EXEC_CODE_SIZE_BYTES + PROG_NAME_LENGTH + COMMENT_LENGTH + NULL_RANGE_BYTES;
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

t_champ 	*parse_champ(t_buf *buf) {
	t_champ *champ;

	if (to_uint32(buf->bytes) != COREWAR_EXEC_MAGIC)
	{
		ft_putendl_fd("wrong magic number", STDERR_FILENO);
		return (NULL);
	}
	champ = (t_champ *) xmalloc(sizeof(t_champ));
	champ->name = get_champ_name(buf->bytes);
	champ->exec_code_size = get_champ_exec_code_size(buf->bytes);
	champ->comment = get_champ_comment(buf->bytes);
	if (!(champ->exec_code = get_champ_exec_code(buf->bytes, champ->exec_code_size)))
	{
		free_champ(champ);
		return (NULL);
	}
	return (champ);
}
