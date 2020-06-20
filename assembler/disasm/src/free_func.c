#include "disasm.h"

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
