/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:20:51 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:21:07 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			len_str(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[0] == '-' && i == 1)
		return (0);
	return (i);
}

static int	direct(t_cmnd *c, char *line, int n, int ar)
{
	if (ar == 1)
	{
		c->cod += 128;
		c->arg1->bite = g_bite;
		g_bite += (n > 8 && n < 16 && n != 13) ? 2 : 4;
		c->arg1->size = (n > 8 && n < 16 && n != 13) ? 2 : 4;
		if (line[1] == LABEL_CHAR)
			return (label_in_com(line, c->arg1));
		else
			c->arg1->arg = ft_atoi_max(line + 1);
		if (len_str(line + 1) < 1)
			return (err_line("Error instruction in line "));
		return (len_str(line + 1) + 1);
	}
	c->arg2->bite = g_bite;
	g_bite += (n > 9) ? 2 : 4;
	c->cod += 32;
	c->arg2->size = (n > 9) ? 2 : 4;
	if (line[1] == LABEL_CHAR)
		return (label_in_com(line, c->arg2));
	else
		c->arg2->arg = ft_atoi_max(line + 1);
	if (len_str(line + 1) < 1)
		return (err_line("Error instruction in line "));
	return (len_str(line + 1) + 1);
}

static int	t_ind(t_cmnd *c, char *line, int n, int ar)
{
	if (ar == 1)
	{
		c->arg1->bite = g_bite;
		g_bite += 2;
		c->arg1->size = 2;
		c->cod += 192;
		if (line[0] == LABEL_CHAR)
			return (label_in_com(line, c->arg1));
		else
			c->arg1->arg = ft_atoi_max(line);
		if (len_str(line) < 1)
			return (err_line("Error instruction in line "));
		return (len_str(line));
	}
	c->arg2->bite = g_bite;
	g_bite += 2;
	c->arg2->size = 2;
	c->cod += 48;
	if (line[0] == LABEL_CHAR)
		return (label_in_com(line, c->arg2));
	else
		c->arg2->arg = ft_atoi_max(line);
	if (len_str(line) < 1)
		return (err_line("Error instruction in line "));
	return (len_str(line));
}

int			arg2(char *line, t_cmnd *c, int n)
{
	int i;

	if (line[0] == 'r')
	{
		c->arg2->bite = g_bite;
		c->cod += 16;
		g_bite += 1;
		c->arg2->size = 1;
		if ((c->arg2->arg = ft_atoi(line + 1)) && (c->arg2->arg > REG_NUMBER
			|| c->arg2->arg < 1))
			return (err_line("Error instruction in line "));
		return (len_str(line + 1) + 1);
	}
	else if (line[0] == DIRECT_CHAR && ((n > 5 && n < 12) || n == 14))
		return (direct(c, line, n, 2));
	else if (n == 3 || (n > 5 && n < 9) || n == 11)
		return (t_ind(c, line, n, 2));
	return (err_line("Error command or argument in line "));
}

int			arg1(char *line, t_cmnd *c, int n)
{
	if (line[0] == 'r' && ((n > 2 && n < 9) || n == 10
		|| n == 11 || n == 14 || n == 16))
	{
		c->arg1->bite = g_bite;
		c->cod += 64;
		g_bite += 1;
		c->arg1->size = 1;
		if ((c->arg1->arg = ft_atoi(line + 1)) && (c->arg1->arg > REG_NUMBER ||
			c->arg1->arg < 1))
			return (err_line("Error instruction in line "));
		return (len_str(line + 1) + 1);
	}
	else if (line[0] == DIRECT_CHAR && (n == 1 || n == 2 || (n > 5 && n < 11)
		|| (n > 11 && n < 16)))
		return (direct(c, line, n, 1));
	else if (n == 2 || (n > 5 && n < 9) || n == 10 || n == 13 || n == 14)
		return (t_ind(c, line, n, 1));
	return (err_line("Error command or argument in line "));
}
