/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:29:15 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:29:16 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	end_com_name(int n, int i, t_header *head, char *line)
{
	if (error_name_com(n, i + ft_while_not_n(line, '"'), line) < 0)
		return (-1);
	if (n == 0)
		ft_copy_unt(head->prog_name + i, line, '"');
	else
		ft_copy_unt(head->comment + i, line, '"');
	i = ft_while_not_n(line, '"') + 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0' && line[i] != ';' &&
		line[i] != COMMENT_CHAR)
	{
		free(line);
		return (err_line("Don`t find end at the line "));
	}
	free(line);
	return (1);
}

static int	next_line(int n, t_header *head, char *line, int fd)
{
	char	*str;
	int		i;

	str = ft_strdup(line);
	str = joinfree(str, "\n", 1);
	while (get_next_line(fd, &line) > 0 && ft_while_not_n(line, '"') < 0)
	{
		g_file++;
		str = joinfree(str, line, 3);
		str = joinfree(str, "\n", 1);
		if (error_name_com(n, ft_strlen(str), str) < 0)
			return (-1);
	}
	g_file++;
	if (!line)
		return (ret_err("Insufficient data"));
	if (n == 0)
		ft_copy_unt(head->prog_name, str, '"');
	else
		ft_copy_unt(head->comment, str, '"');
	i = ft_strlen(str);
	free(str);
	return (end_com_name(n, i, head, line));
}

static int	check_name_comment(t_header *head, int n, char *line, int fd)
{
	int		l;
	int		i;

	if (line[0] != '"')
		return (err_line("Lexical error at line: "));
	i = ft_while_not_n(line + 1, '"');
	if (i < 0)
		return (next_line(n, head, line + 1, fd));
	else
	{
		if (n == 0 && i > PROG_NAME_LENGTH)
			return (ret_err("Name too long"));
		else if (n == 1 && i > COMMENT_LENGTH)
			return (ret_err("Comment too long"));
		while (line[i + 2] == ' ' || line[i + 2] == '\t')
			i++;
		if (line[i + 2] != '\0' && line[i + 2] != ';' &&
			line[i + 2] != COMMENT_CHAR)
			return (err_line("Don`t find end at the line "));
		return (n == 1 ? ft_copy_unt(head->comment, line + 1, '"') :
			ft_copy_unt(head->prog_name, line + 1, '"'));
	}
}

static int	copy_name_comment(char *line, t_header *head, int fd, int l_com)
{
	int l_na;

	l_na = ft_strlen(NAME_CMD_STRING);
	if (ft_strncmp(NAME_CMD_STRING, line, l_na) == 0)
	{
		if (g_name == 1)
			return (ret_err("Name already exists"));
		while (line[l_na] == ' ' || line[l_na] == '\t')
			l_na++;
		if ((g_name = 1) && check_name_comment(head, 0, line + l_na, fd) < 0)
			return (-1);
		return (1);
	}
	else if (ft_strncmp(COMMENT_CMD_STRING, line, l_com) == 0)
	{
		if (g_comm == 1)
			return (ret_err("Comment alredy exist"));
		while (line[l_com] == ' ' || line[l_com] == '\t')
			l_com++;
		if ((g_comm = 1) && check_name_comment(head, 1, line + l_com, fd) < 0)
			return (-1);
		return (1);
	}
	else
		return (ret_err("Impossible to find name or comment"));
}

int			name_comment(int fd, t_header *head)
{
	char	*line;
	int		n;
	int		k;

	k = 0;
	while (get_next_line(fd, &line) > 0)
	{
		n = 0;
		g_file++;
		while (line[n] != '\0' && (line[n] == ' ' || line[n] == '\t'))
			n++;
		if (line[n] != '\0' && line[n] != COMMENT_CHAR && line[n] != ';')
		{
			if (copy_name_comment(line + n, head, fd,
				ft_strlen(COMMENT_CMD_STRING)) < 0)
			{
				free(line);
				return (-1);
			}
		}
		free(line);
		if (g_name == 1 && g_comm == 1)
			return (1);
	}
	return (err_line("Syntax error at token "));
}
