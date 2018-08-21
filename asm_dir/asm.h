/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:16:21 by ismus             #+#    #+#             */
/*   Updated: 2017/10/25 19:16:23 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "new_lib/libft.h"
# include "../const.h"

typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_arg
{
	intmax_t		arg;
	int				bite;
	int				size;
	char			*label;
}					t_arg;

typedef struct		s_cmnd
{
	char			*name;
	int				oper;
	int				cod;
	t_arg			*arg1;
	t_arg			*arg2;
	t_arg			*arg3;
	unsigned int	bite;
	int				l_file;
	struct s_cmnd	*next;

}					t_cmnd;

int					g_file;
int					g_name;
int					g_comm;
int					g_bite;

t_cmnd				*parcing(int fd, t_header *head, char *line, t_cmnd *copy);
int					name_comment(int fd, t_header *head);
t_cmnd				*init_cmnd(void);
int					check_oper(char *line, t_cmnd *cmnd);
int					change_coord(t_cmnd *cmnd);
int					free_all(t_header *head, t_cmnd *cmnd, char *line);
int					err_line(char *line);
int					ret_err(char *line);
void				error(char *line);
int					check_oper(char *line, t_cmnd *cmnd);
t_cmnd				*init_cmnd(void);
int					create_file(char *name, t_header *head, t_cmnd *cmnd);
int					oper_exist(char *line, t_cmnd *cmnd);
int					end_line(char *line);
int					label_in_com(char *line, t_arg *arg);
int					arg2(char *line, t_cmnd *c, int n);
int					arg1(char *line, t_cmnd *c, int n);
int					len_str(char *str);
int					error_name_com(int n, int i, char *str);

#endif
