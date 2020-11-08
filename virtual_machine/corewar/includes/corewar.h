/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:25:59 by aashara-          #+#    #+#             */
/*   Updated: 2020/11/05 18:08:18 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "server.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define OP_CODE_LEN 1
# define ARGS_CODE_LEN 1
# define REG_LEN 1

typedef struct		s_player
{
	int				last_live;
	int				lives_in_cur_period;
	char			name[PROG_NAME_LENGTH];
	char			comment[COMMENT_LENGTH];
	uint8_t			id;
	uint8_t			*code;
	int32_t			code_size;
}					t_player;

typedef struct		s_cursor
{
	uint32_t		id;
	t_bool			carry;
	uint8_t			op_code;
	ssize_t			last_live;
	int				cycles_to_exec;
	uint8_t			args_types[3];
	int32_t			pc;
	uint32_t		step;
	int32_t			reg[REG_NUMBER];
	t_player		*player;
	struct s_cursor	*next;
}					t_cursor;

typedef struct		s_vm
{
	t_player		*players[MAX_PLAYERS];
	t_player		*tmp_players[MAX_PLAYERS];
	u_int8_t		arena[MEM_SIZE];
	t_player		*last_alive;
	t_cursor		*cursor;
	t_cursor		*prev;
	int				num_players;
	int				num_cursor;
	ssize_t			cycle;
	ssize_t			cycle_to_die;
	ssize_t			cycle_after_check;
	int				nbr_live;
	ssize_t			max_checks;
	int				dump_print_mode;
	int				dump;
	t_bool			logs;
	t_bool			aff;
	t_bool			vs;
	char			*vs_ip;
	int				listenfd;
	t_vis_arena		vs_arena;
}					t_vm;

typedef struct		s_op
{
	char			*name;
	uint8_t			code;
	uint8_t			args_num;
	t_bool			args_types_code;
	uint8_t			args_types[3];
	t_bool			modify_carry;
	uint8_t			t_dir_size;
	uint32_t		cycles;
	void			(*func)(t_vm *, t_cursor *);
}					t_op;

/*
**					additional.c
*/
void				ft_exit(char *str);
int32_t				bytecode_to_int32(const uint8_t *arena, int32_t addr,
								int32_t size);
void				int32_to_bytecode(uint8_t *arena, int32_t addr,
								int32_t value, int32_t size);
int32_t				get_op_arg(t_vm *vm, t_cursor *cursor, int index,
								t_bool mod);
/*
**					calculate.c
*/
int32_t				calc_addr(int32_t addr);
uint32_t			step_size(uint8_t arg_type, t_op *op);
void				move_cursor(t_cursor *cursor);
uint32_t			calc_step(t_cursor *cursor, t_op *op);
int8_t				get_byte(t_vm *vm, int32_t pc, int32_t step);
/*
**					check.c
*/
void				help(void);
void				reset_lives_nums(t_vm *vm);
t_cursor			*remove_carriage(t_vm *vm, t_cursor *cursor);
void				delete_cursor(t_vm *vm);
void				check_map(t_vm *vm);
/*
**					check_count_cor_files.c
*/
int					is_cor_file(char *name);
int					check_count_cor_files(char **argv);
/*
**					fill_arena.c
*/

void				add_code_of_players(t_vm *vm);
void				fill_arena(t_vm *vm);
void				fill_players(t_vm *vm);
void				add_struct_for_vs(t_vm *vm);
/*
**					init.c
*/
t_cursor			*init_cursor(t_player *player, int32_t pc);
void				init_arena(t_vm *vm);
void				init_vm_players(t_vm *vm);
t_player			*init_player(int id);
t_vm				*init_vm(void);
/*
**					is_int.c
*/
int					atoi_check_int(const char *str);
int					is_str_digits(char *str);
int					is_int(char *str);
/*
**					main.c
*/
void				add_cursor(t_cursor **list, t_cursor *new);
void				set_cursors(t_vm *vm);
void				player_introduction(t_vm *vm);
void				free_vm(t_vm *vm);
/*
**					parse_args.c
*/
t_player			*find_player(t_vm *vm, int id);
void				parse_dump_flag(int *argc, char ***argv, t_vm *vm);
void				parse_log_flag(int *argc, char ***argv, t_vm *vm);
void				parse_aff_flag(int *argc, char ***argv, t_vm *vm);
void				parse_args(char **argv, int argc, t_vm *vm);
/*
**					parse_champion.c
*/
void				copy_name(t_player *player, int fd);
void				copy_comment(t_player *player, int fd);
int32_t				u_int8_to_u_int32(const u_int8_t *bytecode, int size);
int32_t				check_reg_size(int fd);
char				*parse_str(int fd, int len);
uint8_t				*parse_code(int fd, int code_size);
t_player			*parse_champion(char *cor_file, int id);
/*
**					parse_cor_file.c
*/
void				add_player(t_vm *vm, t_player *player);
void				sort_id_player(t_vm *vm);
void				update_players_id(t_vm *vm);
void				check_double_ids(t_vm *vm);
void				parse_cor_file(int *argc, char ***argv, t_vm *vm);
/*
**					run_vm.c
*/
void				set_cycle_to_exec(t_vm *vm, t_cursor *cursor);
void				op_code_for_cursor(t_vm *vm, t_cursor *cursor);
void				false_cursor(t_vis_arena *vs_arena);
void				exec(t_vm *vm);
void				run_vm(t_vm *vm);
/*
**					validate.c
*/
void				parse_types_args(t_vm *vm, t_op *op, t_cursor *cursor);
t_bool				is_register(t_vm *vm, int32_t pc, int32_t step);
t_bool				validate_args(t_vm *vm, t_cursor *cursor, t_op *op);
t_bool				val_args_types(t_cursor *cursor, t_op *op);
/*
**					vs_ip.c
*/
t_bool				check_ip_split(char **ip_split);
t_bool				is_ip(char *ip);
void				parse_vs_flag(int *argc, char ***argv, t_vm *vm);
/*
**					output.c
*/
void				print_log(t_vm *vm, t_cursor *cursor);
void				output_arena(unsigned char *arena, int print_mode);
void				dump_output(t_vm *vm);

t_cursor			*copy_cursor(t_cursor *cursor, int32_t addr);

/*
**					OPERATIONS
*/
void				op_live(t_vm *vm, t_cursor *cursor);

void				op_ld(t_vm *vm, t_cursor *cursor);

void				op_st(t_vm *vm, t_cursor *cursor);

void				op_add(t_vm *vm, t_cursor *cursor);

void				op_sub(t_vm *vm, t_cursor *cursor);

void				op_and(t_vm *vm, t_cursor *cursor);

void				op_or(t_vm *vm, t_cursor *cursor);

void				op_xor(t_vm *vm, t_cursor *cursor);

void				op_zjmp(t_vm *vm, t_cursor *cursor);

void				op_ldi(t_vm *vm, t_cursor *cursor);

void				op_sti(t_vm *vm, t_cursor *cursor);

void				op_fork(t_vm *vm, t_cursor *cursor);

void				op_lld(t_vm *vm, t_cursor *cursor);

void				op_lldi(t_vm *vm, t_cursor *cursor);

void				op_lfork(t_vm *vm, t_cursor *cursor);

void				op_aff(t_vm *vm, t_cursor *cursor);


static t_op			g_op[16] =
{
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = False,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = True,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = True,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = True,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = False,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = True,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = True,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = True,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = True,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = True,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = False,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = False,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = False,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = False,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = True,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = True,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = True,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = True,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = False,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = False,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = True,
		.args_types = {T_REG, 0, 0},
		.modify_carry = False,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &op_aff
	}
};

#endif
