/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:28:54 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:28:55 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	find_label(char *line, t_cmnd *cmnd)
{
	int i;

	i = 0;
	while (line[i] && ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == LABEL_CHAR)
	{
		cmnd->name = (char *)malloc(sizeof(char) * (1 + i));
		ft_copy_unt(cmnd->name, line, LABEL_CHAR);
		return (i + 1);
	}
	return (0);
}

static int	check_line(char *line, t_cmnd *cmnd)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		i = i + find_label(line + i, cmnd);
		if (check_oper(line + i, cmnd) == -1)
			return (0);
	}
	return (1);
}

static int	double_label(t_cmnd *cmnd)
{
	t_cmnd *copy;

	while (cmnd)
	{
		copy = cmnd->next;
		while (copy)
		{
			if (cmnd->name && copy->name &&
				ft_strcmp(copy->name, cmnd->name) == 0
				&& cmnd->bite != copy->bite)
				return (ret_err("Label names are repeated"));
			copy = copy->next;
		}
		cmnd = cmnd->next;
	}
	return (1);
}

t_cmnd		*parcing(int fd, t_header *head, char *line, t_cmnd *copy)
{
	t_cmnd	*cmnd;

	if (name_comment(fd, head) < 0)
	{
		free(head);
		return (0);
	}
	cmnd = init_cmnd();
	copy = cmnd;
	while (get_next_line(fd, &line))
	{
		if (copy->oper != 0 || copy->name != 0)
		{
			copy->next = init_cmnd();
			copy = copy->next;
		}
		g_file++;
		copy->l_file = g_file;
		if (check_line(line, copy) == 0)
			return (free_all(head, cmnd, line) == 0 ? NULL : NULL);
		free(line);
	}
	if (double_label(cmnd) == -1 || change_coord(cmnd) < 0)
		return (free_all(head, cmnd, 0) == 0 ? NULL : NULL);
	return (cmnd);
}
