#ifndef __DISASM_H__
#define __DISASM_H__

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>

#include "op.h"
#include "libft.h"

#define USAGE "usage: disasm [file.cor]"
#define BUF_SIZE 4096
#define NULL_RANGE_BYTES 4
#define EXEC_CODE_SIZE_BYTES 4
#define MAGIC_HEADER_SIZE_BYTES 4

typedef enum
{
	false,
	true
}	t_bool;


typedef struct		s_buf
{
	u_int8_t 		*bytes;
	size_t			size;
}					t_buf;

typedef struct		s_champ
{
	unsigned		id;
	unsigned char 	*name;
	unsigned char	*comment;
	size_t			exec_code_size;
	char			*exec_code;
}					t_champ;

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	t_bool		args_types_code;
	uint8_t		args_types[3];
	uint8_t		t_dir_size;
}				t_op;

/*
** Array
*/

t_op		g_op[16] = {
		{
				.name = "live",
				.code = 0x01,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = 4,
		},
		{
				.name = "ld",
				.code = 0x02,
				.args_num = 2,
				.args_types_code = true,
				.args_types = {T_DIR | T_IND, T_REG, 0},
				.t_dir_size = 4,
		},
		{
				.name = "st",
				.code = 0x03,
				.args_num = 2,
				.args_types_code = true,
				.args_types = {T_REG, T_REG | T_IND, 0},
				.t_dir_size = 4,
		},
		{
				.name = "add",
				.code = 0x04,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG, T_REG, T_REG},
				.t_dir_size = 4,
		},
		{
				.name = "sub",
				.code = 0x05,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG, T_REG, T_REG},
				.t_dir_size = 4,
		},
		{
				.name = "and",
				.code = 0x06,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.t_dir_size = 4,
		},
		{
				.name = "or",
				.code = 0x07,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.t_dir_size = 4,
		},
		{
				.name = "xor",
				.code = 0x08,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.t_dir_size = 4,
		},
		{
				.name = "zjmp",
				.code = 0x09,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = 2,
		},
		{
				.name = "ldi",
				.code = 0x0A,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.t_dir_size = 2,
		},
		{
				.name = "sti",
				.code = 0x0B,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
				.t_dir_size = 2,
		},
		{
				.name = "fork",
				.code = 0x0C,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = 2,
		},
		{
				.name = "lld",
				.code = 0x0D,
				.args_num = 2,
				.args_types_code = true,
				.args_types = {T_DIR | T_IND, T_REG, 0},
				.t_dir_size = 4,
		},
		{
				.name = "lldi",
				.code = 0x0E,
				.args_num = 3,
				.args_types_code = true,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.t_dir_size = 2,
		},
		{
				.name = "lfork",
				.code = 0x0F,
				.args_num = 1,
				.args_types_code = false,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = 2,
		},
		{
				.name = "aff",
				.code = 0x10,
				.args_num = 1,
				.args_types_code = true,
				.args_types = {T_REG, 0, 0},
				.t_dir_size = 4,
		}
};

t_champ	*validate_and_parse(char *fname);

/*
 * err
 */
void	fatal_error(char *mes);
void	file_error(const char *fname, const char *mes);

/*
 * util
 */
void	*xmalloc(size_t size);

/*
 * free_func
 */
void	free_buf(t_buf *buf);
void	free_champ(t_champ *champ);

/*
 * convert_bytes
 */
uint32_t to_uint32(uint8_t *mas);

/*
 * parse_champ
 */
t_champ 	*parse_champ(t_buf *buf);

#endif