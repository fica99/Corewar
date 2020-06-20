#include "disasm.h"
#include "disasm_op.h"

static unsigned char	*get_champ_name(uint8_t *bytes)
{
	unsigned char *ret;

	ret = (unsigned char *)xmalloc(PROG_NAME_LENGTH + 1);
	ft_memcpy(ret, bytes + MAGIC_HEADER_SIZE_BYTES, PROG_NAME_LENGTH);
	return (ret);
}

static unsigned char *get_champ_comment(uint8_t *bytes)
{
	unsigned char *ret;

	bytes += MAGIC_HEADER_SIZE_BYTES + NULL_RANGE_BYTES + EXEC_CODE_SIZE_BYTES + PROG_NAME_LENGTH;
	ret = (unsigned char *)xmalloc(COMMENT_LENGTH + 1);
	ft_memcpy(ret, bytes, COMMENT_LENGTH);
	return (ret);
}

static size_t get_champ_exec_code_size(uint8_t *bytes)
{
	bytes += MAGIC_HEADER_SIZE_BYTES + PROG_NAME_LENGTH + NULL_RANGE_BYTES;

	return to_uint32(bytes);
}

static t_op *get_champ_exec_code(uint8_t *bytes)
{
	bytes += MAGIC_HEADER_SIZE_BYTES + NULL_RANGE_BYTES +
			EXEC_CODE_SIZE_BYTES + PROG_NAME_LENGTH + COMMENT_LENGTH;
	(void)g_op;
	return NULL;
}

t_champ 	*parse_champ(t_buf *buf)
{
	t_champ *champ;

	if (to_uint32(buf->bytes) != COREWAR_EXEC_MAGIC)
		return (NULL);
	champ = (t_champ *)xmalloc(sizeof(t_champ));
	champ->name = get_champ_name(buf->bytes);
	champ->exec_code_size = get_champ_exec_code_size(buf->bytes);
	champ->comment = get_champ_comment(buf->bytes);
	champ->exec_code = get_champ_exec_code(buf->bytes);	//todo
	return (champ);
}