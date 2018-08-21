/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:29:50 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:29:52 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		free_arg(t_cmnd *cmnd)
{
	if (cmnd->arg1)
	{
		if (cmnd->arg1->label)
			free(cmnd->arg1->label);
		free(cmnd->arg1);
	}
	if (cmnd->arg2)
	{
		if (cmnd->arg2->label)
			free(cmnd->arg2->label);
		free(cmnd->arg2);
	}
	if (cmnd->arg3)
	{
		if (cmnd->arg3->label)
			free(cmnd->arg3->label);
		free(cmnd->arg3);
	}
}

int				free_all(t_header *head, t_cmnd *cmnd, char *line)
{
	t_cmnd *copy;

	if (line)
		free(line);
	if (head)
		free(head);
	while (cmnd)
	{
		if (cmnd->name)
			free(cmnd->name);
		free_arg(cmnd);
		copy = cmnd;
		cmnd = cmnd->next;
		free(copy);
	}
	return (0);
}

static int		first_error(int n, char *str)
{
	int fd;

	if (n != 2)
		error("Usage: ./asm <champ.s>");
	if (ft_strlen(str) < 3 || str[ft_strlen(str) - 1] != 's' ||
		str[ft_strlen(str) - 2] != '.')
		error("File must end with '.s'");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error("Cannot open file.");
	return (fd);
}

static t_header	*header(void)
{
	t_header	*new;

	if (!(new = (t_header*)malloc(sizeof(t_header))))
		return (NULL);
	new->magic = COREWAR_EXEC_MAGIC;
	new->prog_size = 0;
	g_file = 0;
	g_name = 0;
	g_comm = 0;
	ft_bzero(new->prog_name, PROG_NAME_LENGTH);
	ft_bzero(new->comment, COMMENT_LENGTH);
	return (new);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_header	*head;
	t_cmnd		*cmnd;

	fd = first_error(argc, argv[1]);
	head = header();
	g_bite = 0;
	if (!(cmnd = parcing(fd, head, 0, 0)))
	{
		close(fd);
		return (0);
	}
	create_file(argv[1], head, cmnd);
	free_all(head, cmnd, 0);
	close(fd);
	return (0);
}
