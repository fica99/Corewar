/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 20:22:41 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/05 22:40:04 by olegmulko        ###   ########.fr       */
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
# include <sys/stat.h>
# include "op.h"
# include "libft.h"
# include "libhash.h"

# define READ_BUF_SIZE 5
# define STR_MALOC_SIZE 1
# define OPERS_SIZE 16
# define DEFAULT_BIN_DATA_SIZE 4096
# define BIN_DATA_SIZE 4096
# define BIN_DATA_MASK 0b00001111
# define ALT_COMMENT_CHAR ';'
# define LABELS_SIZE 10
# define ARGS_SIZE 3
# define REG_WIDTH 2

/*
** Operations arguments according to the operations table
** The renewed one in 3.Assembler:
** https://github.com/fica99/Corewar/wiki
*/

# define ARG_1_ALL 0b0000000111
# define ARG_1_REG 0b0000000100
# define ARG_1_DIR 0b0000000010
# define ARG_1_IND 0b0000000001
# define ARG_2_ALL 0b0000111000
# define ARG_2_REG 0b0000100000
# define ARG_2_DIR 0b0000010000
# define ARG_2_IND 0b0000001000
# define ARG_3_ALL 0b0111000000
# define ARG_3_REG 0b0100000000
# define ARG_3_DIR 0b0010000000
# define ARG_3_IND 0b0001000000
# define ARG_TYPE 0b1000000000

# define ARG_TYPE_REG 0b01000000
# define ARG_TYPE_DIR 0b10000000
# define ARG_TYPE_IND 0b11000000

# define ERR_INPUT_PARAMS_FIRST "Error: the program accepts only one "
# define ERR_INPUT_PARAMS_SEC "parameter as input (the full path to the file)"
# define ERR_INPUT_PARAMS ERR_INPUT_PARAMS_FIRST ERR_INPUT_PARAMS_SEC
# define ERR_FILE_EXT "Error: the file must have the extension .s"
# define ERR_TMP "line ?: position ?, Error: ?"
# define ERR_LEX "lexical analysis"
# define ERR_STR_CLOSE "the line is not closed"
# define ERR_BIN_DATA_ADD_SIZE "number of bytes to write cannot exceed 4"
# define ERR_FILE_NAME_NULL "the file name specified in the constructor is NULL"
# define ERR_FUNC_PRMS "invalid function parameters"
# define ERR_NULL_POINTER "NULL pointer in parameters"

/*
** Parser errors
*/

# define ERR_PARSER "incorrect parsing order"
# define ERR_CHAMP_NAME "missing champion name token"
# define ERR_MIS_STR "missing string token"
# define ERR_CHAMP_NAME_LEN "the champion name too big"
# define ERR_CHAMP_COMMENT "missing champion comment token"
# define ERR_CHAMP_COMMENT_LEN "the champion comment too big"
# define ERR_MIS_OPER "missing operation token"
# define ERR_MIS_ARG_SEP "missing argument separator"
# define ERR_NOT_ARG "token is not an argument"
# define ERR_INVALID_ARG "invalid argument for the operation or position"
# define ERR_MIS_ARG "missing argument token"
# define ERR_MIS_NL "missing line break"
# define ERR_REG_SIZE "the register number is greater than the allowed value"
# define ERR_LABEL "reference to non-existent label"
# define ERR_CAST_TYPE "cast the data type of the token"

typedef enum			e_asm_errors
{
	ASM_ERR_GENERAL,
	ASM_ERR_CHAMP_NAME,
	ASM_ERR_MIS_STR,
	ASM_ERR_CHAMP_NAME_LEN,
	ASM_ERR_CHAMP_COMMENT,
	ASM_ERR_CHAMP_COMMENT_LEN,
	ASM_ERR_FUNC_PRMS,
	ASM_ERR_MIS_OPER,
	ASM_MIS_ARG_SEP,
	ASM_ERR_NOT_ARG,
	ASM_ERR_INVALID_ARG,
	ASM_ERR_MIS_ARG,
	ASM_ERR_MIS_NL,
	ASM_ERR_REG_SIZE,
	ASM_ERR_LABEL,
	ASM_ERR_CAST_TYPE,
}						t_asm_errors;

typedef struct			s_asm_string
{
	char				*str;
	size_t				size;
	size_t				m_size;
	size_t				line_num;
	size_t				char_num;
	size_t				index;
}						t_asm_string;

typedef enum			e_asm_tkn_type
{
	TT_EOF,
	TT_SEP,
	TT_NEWLINE,
	TT_STRING,
	TT_COMMENT,
	TT_CHAMP_NAME,
	TT_CHAMP_COMMENT,
	TT_LABEL,
	TT_ARG_REG,
	TT_ARG_DIR,
	TT_ARG_IND,
	TT_OPER,
	TT_ARG_SEP,

}						t_asm_tkn_type;

typedef enum			e_asm_type_conv
{
	TC_STR,
	TC_SIZE_T,
}						t_asm_type_conv;

/*
** Operations according to the operations table
** The renewed one in 3.Assembler:
** https://github.com/fica99/Corewar/wiki
*/

typedef struct			s_asm_oper
{
	char				*name;
	char				code;
	char				dir_size;
	int					args_mask;
}						t_asm_oper;

typedef struct			s_asm_token
{
	void				*data;
	t_asm_tkn_type		type;
	t_asm_type_conv		type_conv;
	size_t				line_num;
	size_t				char_num;
	struct s_asm_token	*next;
}						t_asm_token;

typedef struct			s_asm_bin_data
{
	char				*data;
	size_t				index;
	size_t				m_size;
	size_t				size;
	char				part;
	void				(*check_size)(struct s_asm_bin_data *);
	void				(*add)(struct s_asm_bin_data *, int, int);
}						t_asm_bin_data;

typedef struct			s_asm_file
{
	char				*name;
	char				*exp;
	int					fd;
	void				(*open)(struct s_asm_file *, int, int);
	void				(*write_bin_data)(struct s_asm_file *,
							t_asm_bin_data *);
}						t_asm_file;

typedef struct			s_asm_label
{
	char				*name;
	int					count;
}						t_asm_label;

typedef struct			s_asm_labels
{
	t_asm_label			*labels;
	size_t				size;
	size_t				m_size;
	int					(*is_contain)(struct s_asm_labels *, char *);
	int					(*add)(struct s_asm_labels *, char *, int);
	void				(*clear)(struct s_asm_labels *);
	void				(*inc)(struct s_asm_labels *, size_t);
}						t_asm_labels;

typedef struct			s_asm_pars_prms
{
	int					exec_code_size;
	int					args_mask;
	char				mask_offset;
	char				dir_size;
	int					oper_byte_index;
	char				*error;
	t_asm_labels		*labels;
	size_t				line_num;
	size_t				char_num;
}						t_asm_pars_prms;

/*
** asm_error.c
*/

void					asm_sys_error(void);
void					asm_prog_error(char *msg);
void					asm_lex_error(t_asm_string *asm_str, char *msg);
void					asm_pars_error(t_asm_pars_prms	*prms);

/*
** asm_new_str.c
*/

t_asm_string			*asm_new_str(size_t m_size);

/*
** asm_strs_realoc.c
*/

void					asm_str_realoc(t_asm_string *asm_str);

/*
** asm_lex_token.c
*/

t_asm_token				*asm_lex_new_token(t_asm_tkn_type type);
void					asm_lex_del_token(t_asm_token **token);

/*
** asm_filetostr.c
*/

t_asm_string			*asm_file_to_str(char *file_path);

/*
** asm_lex_get_token.c
*/

t_asm_token				*asm_lex_get_token(t_asm_string *asm_str,
									t_hash **opers_hash);
/*
** asm_lex_token_comment.c
*/

t_asm_token				*asm_lex_token_comment(t_asm_string *asm_str);
t_asm_token				*asm_lex_del_com_token(t_asm_token *token);
t_asm_token				*asm_lex_del_all_com_tokens(t_asm_token *token);
/*
** asm_ltoa.c
*/

char					*asm_ltoa(long long num);
/*
** asm_lex_get_chain_tokens.c
*/

t_asm_token				*asm_lex_get_chain_tokens(t_asm_string *asm_str,
							t_hash **opers_hash);
/*
** asm_lex_token_nl.c
*/

t_asm_token				*asm_lex_token_nl(t_asm_string *asm_str);
/*
** asm_lex_token_str.c
*/

t_asm_token				*asm_lex_token_str(t_asm_string *asm_str);
/*
** asm_lex_token_chn.c
*/

int						asm_lex_is_champ_name(t_asm_string *asm_str);
t_asm_token				*asm_lex_token_champ_name(t_asm_string *asm_str);
/*
** asm_lex_token_chcom.c
*/

int						asm_lex_is_champ_comment(t_asm_string *asm_str);
t_asm_token				*asm_lex_token_champ_comment (t_asm_string *asm_str);
/*
** asm_lex_token_sep.c
*/

int						asm_lex_is_sep(t_asm_string *asm_str);
t_asm_token				*asm_lex_token_sep (t_asm_string *asm_str);
/*
** asm_lex_token_label.c
*/

int						asm_lex_is_label(char *str, size_t i, int mod);
char					*asm_lex_get_label_str(t_asm_string *asm_str, char mod);
t_asm_token				*asm_lex_token_label(t_asm_string *asm_str);
/*
** asm_lex_token_arg_reg.c
*/

int						asm_lex_is_number(t_asm_string *asm_str, size_t i);
int						asm_lex_is_arg_reg(t_asm_string *asm_str);
int						*asm_lex_get_number(t_asm_string *asm_str);
t_asm_token				*asm_lex_token_arg_reg(t_asm_string *asm_str);
/*
** asm_lex_token_arg_dir.c
*/

int						asm_lex_is_arg_dir(t_asm_string *asm_str);
t_asm_token				*asm_lex_token_arg_dir(t_asm_string *asm_str);
/*
** asm_lex_token_arg_ind.c
*/

int						asm_lex_is_arg_ind(t_asm_string *asm_str);
t_asm_token				*asm_lex_token_arg_ind(t_asm_string *asm_str);
/*
** asm_opers_hash.c
*/

t_hash					**asm_get_opers_hash();
/*
** asm_lex_opers.c
*/

int						asm_is_oper(t_asm_string *asm_str,
							t_hash **opers_hash);
t_asm_token				*asm_token_oper(t_asm_string *asm_str,
							t_hash **opers_hash);
/*
** asm_lex_arg_sep.c
*/

int						asm_lex_check_arg_sep(t_asm_string *asm_str);
t_asm_token				*asm_lex_token_arg_sep(t_asm_string *asm_str);

/*
** asm_bin_data.c
*/

t_asm_bin_data			*asm_init_bin_data(size_t size);

/*
** asm_file.c
*/

t_asm_file				*asm_file_init(char *name, char *exp);
char					*asm_del_exp(char *filename);

/*
** asm_parser.c
*/

t_asm_pars_prms			*asm_init_pars_prms(void);
void					asm_fill_prms_from_token(t_asm_token *token,
							t_asm_pars_prms *prms, char *error);
int						asm_skip_token(t_asm_token **token,
							t_asm_tkn_type type);
int						asm_parser(t_asm_token *token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms);

/*
** asm_pars_ch_name.c
*/

int						asm_pars_champ_name(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms);

/*
** asm_pars_sep.c
*/

int						asm_check_nl(t_asm_token **token,
							t_asm_pars_prms *prms);

/*
** asm_pars_exec_code.c
*/

int						asm_exec_code(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms);

/*
** asm_pars.ch_com.c
*/

int						asm_pars_champ_comment(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms);

/*
** asm_support_func.c
*/

void					asm_add_null_in_bd(t_asm_bin_data *bin_data,
							int bytes);
void					asm_print_str_filetostr(char *str);
void					asm_pos_to_token(t_asm_string *asm_str,
	t_asm_token *token);

/*
** asm_pars_error.c
*/

int						asm_parser_error(t_asm_token *token,
							t_asm_pars_prms *prms,
							t_asm_errors error);
/*
** asm_pars_opers.c
*/

int						asm_pars_opers(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms);
int						asm_pars_oper(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms);
int 					asm_pars_arg(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms, char arg_index);
int						asm_pars_args_sep(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms, char arg_index);

/*
** asm_pars_labels.c
*/

void					asm_pars_label(t_asm_token **token,
							t_asm_pars_prms *prms);

/*
** asm_obj_label.c
*/

t_asm_labels			*asm_init_labels(size_t size);
int						asm_labels_is_contain(t_asm_labels *labels, char *name);
int						asm_labels_add(t_asm_labels *labels,
							char *name, int count);
void					asm_labels_clear(t_asm_labels *labels);
void					asm_labels_count_inc(t_asm_labels *labels, size_t inc);

/*
** asm_pars_reg.c
*/

int						asm_pars_is_reg(t_asm_token **token,
							t_asm_pars_prms *prms, char arg_index);
int						asm_pars_reg(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms, char arg_index);

/*
** asm_pars_dir.c
*/

int						asm_pars_is_dir(t_asm_token **token,
							t_asm_pars_prms *prms, char arg_index);
int						asm_pars_dir(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms, char arg_index);

/*
** asm_pars_ind.c
*/

int						asm_pars_is_ind(t_asm_token **token,
							t_asm_pars_prms *prms, char arg_index);
int						asm_pars_ind(t_asm_token **token,
							t_asm_bin_data *bin_data,
							t_asm_pars_prms *prms, char arg_index);

/*
** asm_print_str_opers.c
*/

void					asm_print_str_filetostr(char *str);
void					asm_print_opershash(t_hash **opers_hash);
void					asm_print_opershash_data1(t_asm_oper *data);
void					asm_print_opershash_data2(t_asm_oper *data);
void					asm_print_opershash_data3(t_asm_oper *data);

/*
** asm_print_tokens.c
*/

void					asm_print_tokens(t_asm_token *tokens);

/*
** asm_pars_type_args.c
*/

void					asm_pars_type_args(t_asm_token *token,
							t_asm_bin_data *bin_data, t_asm_pars_prms *prms);

#endif
