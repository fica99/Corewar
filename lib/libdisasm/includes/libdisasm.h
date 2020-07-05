/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdisasm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:53:52 by aashara-          #+#    #+#             */
/*   Updated: 2020/06/25 20:53:53 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDISASM_H
# define LIBDISASM_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdint.h>
# include <endian.h>
# include "op.h"
# include "libft.h"

# define DISASM_USAGE "usage: disasm [file.cor]"
# define BUF_SIZE 4096
# define NULL_RANGE_BYTES 4
# define EXEC_CODE_SIZE_BYTES 4
# define MAGIC_HEADER_SIZE_BYTES 4
# define TWO_LAST_BITS (uint8_t)3
# define OP_COUNT 16

typedef enum
{
	false,
	true
}	t_bool;

typedef struct		s_buf
{
	uint8_t	*bytes;
	size_t	size;
}					t_buf;

typedef struct		s_op
{
	char			*name;
	uint8_t			code;
	uint8_t			args_num;
	t_bool			args_types_code;
	uint8_t			args_types[3];
	uint8_t			t_dir_size;
	int32_t			args_val[3];
	struct s_op		*next;
}					t_op;

typedef struct		s_champ
{
	unsigned		id;
	char			*name;
	char			*comment;
	size_t			exec_code_size;
	t_op			*exec_code;
}					t_champ;

t_champ				*validate_and_parse(char *fname);

/*
** err
*/
void				fatal_error(const char *mes);
void				*file_error(const char *fname, const char *mes);

/*
** util
*/
void				*xmalloc(size_t size);

/*
** free_func
*/
void				free_buf(t_buf *buf);
void				free_champ(t_champ *champ);
void				free_op_list(t_op *lst);

/*
** convert_bytes
*/
uint32_t			to_uint32(const uint8_t *mas);
int32_t				convert16(uint16_t x);

/*
** parse_champ
*/
t_champ				*parse_champ(t_buf *buf);

/*
** op_push_back
*/
t_op				*op_push_back(t_op **lst, uint8_t byte);
/*
** fill_op
*/
int					fill_op(t_op *op, const uint8_t *bytes);

#endif