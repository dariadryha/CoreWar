/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:53:58 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:53:59 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "const.h"
# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"

# define SIZE_MES "has a code size that differ from what its header says!"
# define MANY_ARGS ft_error("Too many champions!", NULL)
# define FAIL_OPEN(x) ft_error("Can't read source file", x)
# define INV_PROG_SIZE(x) ft_struct_file(SIZE_MES, x)
# define SMALL_PROG(x) ft_struct_file("is too small to be a champion!", x)
# define INV_MAGIC(x) ft_struct_file("has an invalid header!", x)
# define LARGE_PROG "has too large a code"
# define PROG_NAME PROG_NAME_LENGTH
# define CONTENT (*(t_proc *)data->proc->content)
# define PC CONTENT.pc
# define DELAY CONTENT.delay
# define OP_CODE(x) data->area[x] >= 1 && data->area[x] <= REG_NUMBER ? 1 : 0
# define REG_INDEX(x) x >=1 && x <=16 ? 1 : 0
# define LIVE CONTENT.live
# define ID CONTENT.id
# define INDEX CONTENT.index
# define REG CONTENT.reg
# define CARRY CONTENT.carry
# define PASSED_CYCLES data->passed_cycles[0] + data->passed_cycles[1]
# define CODAGE(x) x == REG_CODE || x == DIR_CODE || x == IND_CODE ? 1 : 0
# define INST CONTENT.inst
# define ARG CONTENT.arg
# define PTR(y) ARG.ptr[y]
# define SHORT_VAL(y) *((short *)(ARG.ptr)[y])
# define T_INT_VAL(y) *((t_int *)(ARG.ptr)[y])
# define SHIFT ARG.shift
# define CHECK_CODAGE(x) x == DIR_CODE || x == IND_CODE || x == REG_CODE ? 1 : 0
# define V_I(x) REG_INDEX(SHORT_VAL(x))
# define VALID_INDEX(x) (!(V_I(x)) && ARG.codage[x] == REG_CODE) ? 1 : 0
# define PROC_NUM ((t_proc *)(data->proc->content))->num
# define DIR read_direct(data)
# define IND read_indirect(data)
# define DUMP_INST data->flg[4][0] ? 1 : 0
# define PC_MOVE data->flg[5][0] ? 1 : 0
# define DEATHS data->flg[6][0] ? 1 : 0
# define LIVES data->flg[7][0] ? 1 : 0
# define VISUAL data->flg[2][0] ? 1 : 0
# define DUMP_MEMORY(x) data->flg[0][0] && data->flg[0][1] == x ? 1 : 0
# define SET_ID data->flg[1][0] ? 1 : 0
# define DO_AFF data->flg[3][0] ? 1 : 0
# define FLGS 8
# define OK "OK"
# define FAIL "FAILED"

typedef	unsigned char	t_char;
typedef	unsigned int	t_int;

typedef struct			s_arg
{
	short				reg[MAX_REG + 1];
	t_int				dir[MAX_DIR + 1];
	short				ind[MAX_IND + 1];
	short				codage[MAX_INST_ARGS];
	void				*ptr[MAX_INST_ARGS];
	int					shift;
}						t_arg;

typedef struct			s_proc
{
	int					pc;
	short				carry;
	int					id;
	t_int				reg[REG_NUMBER + 1];
	t_int				live;
	t_int				inst;
	t_int				delay;
	t_arg				arg;
	t_int				num;
	t_int				no_live;
	t_int				index;
}						t_proc;

typedef struct			s_play
{
	t_int				magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	t_int				prog_size;
	char				comment[COMMENT_LENGTH + 1];
	t_char				*code;
	int					id;
	int					last_live_cycle;
	t_int				total_lives;
}						t_play;

typedef struct			s_data
{
	int					area_players[MEM_SIZE];
	t_char				area[MEM_SIZE];
	t_play				champ[MAX_PLAYERS];
	uintmax_t			num;
	t_int				total_lives;
	t_int				check_cycle;
	t_list				*proc;
	int					cycle_to_die;
	intmax_t			passed_cycles[2];
	int					quantity;
	int					last_live;
	int					flg[FLGS][2];
}						t_data;

void					parse_arguments(t_data *data, int argc, char **argv);
void					ranking_players(t_data *data);
void					parse_codage(t_data *data);
t_int					get_arg_value(t_data *data, int num);
void					start_infernal_game(t_data *data);
void					ft_error(char *str1, char *str2);
void					ft_reverse(void *temp, int x);
void					pc_movements(t_data *data);
void					dump_memory(t_data *data);
void					ft_large(t_int arg1, char *str);
int						check_lives(t_data *data);
void					check_cycle(t_data *data);
void					check_position(int *pos);
void					new_process(t_data *data, int pc);
void					memsub_dst(void *dst, const void *src,
	int start, size_t len);

void					memsub_mark(void *dst, int index,
	int start, size_t len);

void					memsub_src(void *dst, const void *src,
	int start, size_t len);
void					add_to_begin(t_list **head, t_list **new);
void					ft_lstdelif(t_data *data);
void					announcement_of_winner(t_data *data);
void					ft_usage(void);
void					parse_flags(t_data *data, int argc, char **argv);
int						check_arguments(t_data *data, char **str);
void					ft_struct_file(char *str1, char *str2);
void					announcement_of_players(t_data *data);
void					free_data(t_data *data);
void					visu(t_data *data);

void					live(t_data *data);
void					zjmp(t_data *data);
void					sti(t_data *data);
void					ft_and(t_data *data);
void					ld(t_data *data);
void					st(t_data *data);
void					ft_fork(t_data *data);
void					lfork(t_data *data);
void					aff(t_data *data);
void					add(t_data *data);
void					ft_xor(t_data *data);
void					ldi(t_data *data);
void					sub(t_data *data);
void					ft_or(t_data *data);
void					lldi(t_data *data);
void					lld(t_data *data);

#endif
