/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/20 16:03:04 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include "op.h"
# include "libft.h"

# define READ_BUF_SIZE 5
# define STR_MALOC_SIZE 1
# define ALT_COMMENT_CHAR ';'
# define ERR_INPUT_PARAMS_FIRST "Error: the program accepts only one "
# define ERR_INPUT_PARAMS_SEC "parameter as input (the full path to the file)"
# define ERR_INPUT_PARAMS ERR_INPUT_PARAMS_FIRST ERR_INPUT_PARAMS_SEC
# define ERR_FILE_EXT "Error: the file must have the extension .c"
# define ERR_LEX_TMP "line ?: position ?, Error: ?"
# define ERR_LEX "lexical analysis"

typedef struct	s_asm_string
{
	char	*str;
	size_t	size;
	size_t	m_size;
	size_t	line_num;
	size_t	char_num;
	size_t	index;
}				t_asm_string;

typedef enum	e_asm_tkn_type
{
	TT_EOF,
	TT_NEWLINE,
	TT_STRING,
	TT_COMMENT,
}				t_asm_tkn_type;

typedef struct	s_asm_token
{
	void				*data;
	t_asm_tkn_type		type;
	struct s_asm_token	*next;
}				t_asm_token;

void			asm_sys_error(void);
void			asm_prog_error(char *msg);
void			asm_lex_error(t_asm_string *asm_str, char *msg);
t_asm_string	*asm_new_str(size_t m_size);
void			asm_str_realoc(t_asm_string *asm_str);
t_asm_token		*asm_new_token(t_asm_tkn_type type);
t_asm_string	*asm_file_to_str(char *file_path);
t_asm_token		*asm_get_token(t_asm_string *asm_str);
t_asm_token		*asm_proc_comments(t_asm_string *asm_str);
char			*asm_ltoa(long long num);

#endif
