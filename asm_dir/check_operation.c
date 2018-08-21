/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:23:04 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:23:06 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	arg33(char *line, t_cmnd *c, int n)
{
	c->arg3->bite = g_bite;
	g_bite += (n > 9) ? 2 : 4;
	c->arg3->size = (n > 9) ? 2 : 4;
	c->cod += 8;
	if (line[1] == LABEL_CHAR)
		return (label_in_com(line, c->arg3));
	else
		c->arg3->arg = ft_atoi_max(line + 1);
	if (len_str(line + 1) < 1)
		return (err_line("Error instruction in line "));
	return (len_str(line + 1) + 1);
}

static int	arg3(char *line, t_cmnd *c, int n)
{
	if (line[0] == 'r')
	{
		c->arg3->bite = g_bite;
		g_bite += 1;
		c->cod += 4;
		c->arg3->size = 1;
		if ((c->arg3->arg = ft_atoi(line + 1)) && (c->arg3->arg > REG_NUMBER
			|| c->arg3->arg < 1))
			return (err_line("Error instruction in line "));
		return (len_str(line + 1) + 1);
	}
	else if (line[0] == DIRECT_CHAR && n == 11)
		return (arg33(line, c, n));
	return (err_line("Error command or argument in line "));
}

static int	last_arg(char *line, int b, t_cmnd *cmnd, int n)
{
	int i;

	while (line[b + 1] && (line[b + 1] == ' ' || line[b + 1] == '\t'))
		b++;
	if ((i = arg3(line + b + 1, cmnd, n)) && i < 0)
		return (-1);
	b = b + i + 1;
	return (end_line(line + b));
}

static int	check_arg(char *line, t_cmnd *cmnd, int n)
{
	int i;
	int b;

	if ((b = arg1(line, cmnd, n)) && b < 0)
		return (-1);
	while (line[b] && (line[b] == ' ' || line[b] == '\t'))
		b++;
	if (n == 1 || n == 9 || n == 12 || n > 14)
		return (end_line(line + b));
	if (line[b] != SEPARATOR_CHAR)
		return (err_line("There is no separator symbol in line "));
	while (line[b + 1] && (line[b + 1] == ' ' || line[b + 1] == '\t'))
		b++;
	if ((i = arg2(line + b + 1, cmnd, n)) && i < 0)
		return (-1);
	b = b + i + 1;
	while (line[b] && (line[b] == ' ' || line[b] == '\t'))
		b++;
	if (n == 2 || n == 3 || n == 13)
		return (end_line(line + b));
	if (line[b] != SEPARATOR_CHAR)
		return (err_line("There is no separator symbol in line "));
	return (last_arg(line, b, cmnd, n));
}

int			check_oper(char *line, t_cmnd *cmnd)
{
	int i;
	int n;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		i = i + oper_exist(line + i, cmnd);
		if (cmnd->oper == 0)
			return (err_line("Command not found in line "));
		g_bite++;
		if (cmnd->oper != 1 && cmnd->oper != 9 && cmnd->oper != 12
			&& cmnd->oper != 15)
			g_bite++;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (check_arg(line + i, cmnd, cmnd->oper) < 0)
			return (-1);
		if (cmnd->oper == 1 || cmnd->oper == 9 || cmnd->oper == 12 ||
			cmnd->oper == 15)
			cmnd->cod = 0;
	}
	return (1);
}
