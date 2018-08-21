/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:29:05 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:29:05 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			label_in_com(char *line, t_arg *arg)
{
	int i;
	int k;

	i = line[0] == DIRECT_CHAR ? 2 : 1;
	k = i;
	while (line[i] && ft_strchr(LABEL_CHARS, line[i]))
		i++;
	arg->label = ft_strndup(line + k, i - k);
	return (i);
}

int			end_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0' || line[i] == COMMENT_CHAR || line[i] == ';')
		return (1);
	return (err_line("Unknown end of line "));
}

static int	oper_exist2(char *line, t_cmnd *cmnd)
{
	if (!ft_strncmp(line, "ldi", 3) && (cmnd->oper = 10))
		return (3);
	else if (!ft_strncmp(line, "sti", 3) && (cmnd->oper = 11))
		return (3);
	else if (!ft_strncmp(line, "lld", 3) && (cmnd->oper = 13))
		return (3);
	else if (!ft_strncmp(line, "aff", 3) && (cmnd->oper = 16))
		return (3);
	else if (!ft_strncmp(line, "ld", 2) && (cmnd->oper = 2))
		return (2);
	else if (!ft_strncmp(line, "st", 2) && (cmnd->oper = 3))
		return (2);
	return (0);
}

int			oper_exist(char *line, t_cmnd *cmnd)
{
	if (!ft_strncmp(line, "live", 4) && (cmnd->oper = 1))
		return (4);
	else if (!ft_strncmp(line, "lfork", 5) && (cmnd->oper = 15))
		return (5);
	else if (!ft_strncmp(line, "lldi", 4) && (cmnd->oper = 14))
		return (4);
	else if (!ft_strncmp(line, "zjmp", 4) && (cmnd->oper = 9))
		return (4);
	else if (!ft_strncmp(line, "fork", 4) && (cmnd->oper = 12))
		return (4);
	else if (!ft_strncmp(line, "add", 3) && (cmnd->oper = 4))
		return (3);
	else if (!ft_strncmp(line, "sub", 3) && (cmnd->oper = 5))
		return (3);
	else if (!ft_strncmp(line, "and", 3) && (cmnd->oper = 6))
		return (3);
	else if (!ft_strncmp(line, "or", 2) && (cmnd->oper = 7))
		return (2);
	else if (!ft_strncmp(line, "xor", 3) && (cmnd->oper = 8))
		return (3);
	return (oper_exist2(line, cmnd));
}
