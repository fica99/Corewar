/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:12:31 by aashara-          #+#    #+#             */
/*   Updated: 2020/10/28 23:07:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <math.h>
# include "libft.h"

# define PRINTF_BUFF_SIZE 20000
# define TRUE 1
# define FALSE 0
# define ASCII_SIZE 128
# define LONG_DOUBLE_EXP 16383
# define INF_MANTIS 128
# define DEL_SIGN 127
# define MANTIS_LEN 64
# define LONG_DOUBLE_MALLOC_LEN 16500

typedef enum		e_pf_flags
{
	PF_FL_INIT = 0,
	PF_FL_HASH = 1,
	PF_FL_ZERO = 2,
	PF_FL_MINUS = 4,
	PF_FL_PLUS = 8,
	PF_FL_SPACE = 16,
	PF_FL_BIN = 32,
}					t_pf_flags;

typedef enum		e_pf_mod_len
{
	PF_ML_INIT = 0,
	PF_ML_HH,
	PF_ML_H,
	PF_ML_L,
	PF_ML_LL,
	PF_ML_BL,
	PF_ML_J,
	PF_ML_Z,
	PF_ML_T,
}					t_pf_mod_len;

typedef struct		s_printf
{
	va_list			argptr;
	size_t			buff_len;
	size_t			i;
	size_t			malloc_len;
	t_pf_flags		flags;
	t_pf_mod_len	mod;
	size_t			width;
	int				prec;
	char			*buff;
}					t_printf;

typedef struct		s_len_opts
{
	char			sign;
	size_t			num_len;
	size_t			w_len;
	size_t			ac_len;
	size_t			nstr_len;
}					t_len_opts;

/*
**					ft_printf.c
*/
int					ft_printf(const char *format, ...);
/*
**					ft_dprintf.c
*/
void				pf_init_start(t_printf *pf);
int					ft_dprintf(int fd, const char *format, ...);
/*
**					pf_parse.c
*/
void				pf_parse_string(const char *format,
											t_printf *pf);
/*
**					pf_tables.c
*/
t_pf_flags			*pf_flags_table(void);
t_pf_mod_len		*pf_mod_table(void);
void				*pf_spec_table(const char c);
/*
**					pf_spec_handlers.c
*/
void				pf_spec_c(t_printf *pf);
void				pf_spec_s(t_printf *pf);
void				pf_spec_percent(t_printf *pf);
void				pf_spec_int(t_printf *pf);
void				pf_spec_p(t_printf *pf);
/*
**					pf_spec_handlers2.c
*/
void				pf_spec_big_x(t_printf *pf);
void				pf_spec_small_x(t_printf *pf);
void				pf_spec_uint(t_printf *pf);
void				pf_spec_o(t_printf *pf);
/*
**					pf_buff_managment.c
*/
void				pf_add_str(t_printf *pf, char *str);
void				pf_check_mem(t_printf *pf, const size_t add_len);
void				pf_add_symb(t_printf *pf, char c, size_t res_len);
void				pf_add_str_2_buff(t_printf *pf, const char *str,
															const size_t len);
char				pf_check_sign(t_printf *pf, intmax_t nb);
/*
**					pf_convert.c
*/
intmax_t			pf_convert_nb(t_pf_mod_len mod, intmax_t num);
intmax_t			pf_convert_unb(t_pf_mod_len mod, intmax_t num);
size_t				pf_get_nb_size(t_pf_mod_len mod);
size_t				pf_get_unb_size(t_pf_mod_len mod);
char				*pf_get_bits(size_t size, void *ptr);
/*
**					pf_handle_di.c
*/
void				pf_handle_di(t_printf *pf, intmax_t nb, char *str);
/*
**					pf_handle_p.c
*/
void				pf_handle_p(t_printf *pf, intmax_t nb, char *str);
/*
**					pf_handle_x.c
*/
void				pf_handle_x(t_printf *pf, intmax_t nb,
												char *str, char is_big);
/*
**					pf_ltoa.c
*/
char				*ft_ultoa_base(uintmax_t n, int base, char cap);
char				*ft_iltoa(intmax_t num);
/*
**					pf_handle_small_f.c
*/
void				pf_spec_small_f(t_printf *pf);
/*
**					pf_dtoa.c
*/
size_t				pf_dtoa(char **str, long double num, int prec);
/*
**					pf_dtoa_exp_mantis.c
*/
void				pf_exp_mantis2str(char *str, short exp,
										unsigned long mantis);
/*
**					pf_dtoa_long_arith.c
*/
void				pf_carry(char *res, int size, char is_str);
char				*pf_pow(short pow, short exp);
char				*pf_div_pow(char *num, short prev_exp, short exp,
															short pow);
/*
**					pf_dtoa_help.c
*/
void				pf_add_elem2list(char to_start, t_list **head, t_list *el);
t_list				*pf_get_last(t_list *head);
void				pf_dig_overflow(char **content, size_t i, size_t *size,
																char is_str);
char				*pf_update_nums2str(char *str, t_list *el);
/*
**					pf_dtoa_round.c
*/
size_t				pf_dtoa_round(char **str, size_t prec);
/*
**					pf_handle_u.c
*/
void				pf_handle_u(t_printf *pf, intmax_t nb, char *str);
/*
**					pf_len_opts.c
*/
t_len_opts			*pf_init_len_opts(t_printf *pf, intmax_t nb,
	char *str);
size_t				pf_get_num_len(intmax_t nb, char *str, char sign, int prec);
size_t				pf_get_w_len(t_printf *pf, size_t num_len);
size_t				pf_get_ac_len(t_printf *pf, intmax_t nb,
	t_len_opts *len_opts);
/*
**					pf_handle_func.c
*/
void				pf_align_to_width(t_printf *pf, char c,
	t_len_opts	*len_opts);
void				pf_align_to_accuracy(t_printf *pf, char c,
	t_len_opts *len_opts);
void				pf_add_chr(t_printf *pf, char *str);
void				pf_add_chr_2_buff(t_printf *pf, char chr);
void				pf_parse_undefined(const char *format,
	t_printf *pf);
/*
**					pf_handle_o.c
*/
void				pf_handle_o(t_printf *pf, intmax_t nb, char *str);
/*
**					pf_parse_color.c
*/
char				pf_parse_color(const char *format, t_printf *pf);
#endif
