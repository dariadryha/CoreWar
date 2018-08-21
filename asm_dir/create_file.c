/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:30:14 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:30:14 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned int	inverse(unsigned int i, int n)
{
	if (n == 4)
		i = ((i >> 24) & 0xff) | ((i << 8) & 0xff0000) |
			((i >> 8) & 0xff00) | ((i << 24) & 0xff000000);
	if (n == 2)
		i = ((i >> 8) & 0xff) | ((i << 8) & 0xff00);
	return (i);
}

static void			write_command(int fd, t_cmnd *cmnd)
{
	unsigned int inv;

	inv = cmnd->oper;
	write(fd, (char *)(&inv), 1);
	if (cmnd->cod != 0)
		write(fd, (char *)&cmnd->cod, 1);
	if (cmnd->arg1->size != 0)
	{
		inv = inverse(cmnd->arg1->arg, cmnd->arg1->size);
		write(fd, (char *)&inv, cmnd->arg1->size);
	}
	if (cmnd->arg2->size != 0)
	{
		inv = inverse(cmnd->arg2->arg, cmnd->arg2->size);
		write(fd, (char *)&inv, cmnd->arg2->size);
	}
	if (cmnd->arg3->size != 0)
	{
		inv = inverse(cmnd->arg3->arg, cmnd->arg3->size);
		write(fd, (char *)&inv, cmnd->arg3->size);
	}
}

int					create_file(char *name, t_header *head, t_cmnd *cmnd)
{
	char	*name1;
	int		fd;

	if (cmnd->name == 0 && cmnd->oper == 0)
		return (ret_err("Can`t find any command"));
	name1 = joinfree(ft_strndup(name, ft_strlen(name) - 1), "cor", 1);
	if (!(fd = open(name1, O_WRONLY | O_CREAT | O_TRUNC, 0600)))
		return (ret_err("Can`t create the file"));
	head->magic = inverse(COREWAR_EXEC_MAGIC, 4);
	head->prog_size = inverse(g_bite, 4);
	write(fd, head, sizeof(t_header));
	while (cmnd)
	{
		if (cmnd->oper != 0)
			write_command(fd, cmnd);
		cmnd = cmnd->next;
	}
	ft_printf("Writing output program to %s\n", name1);
	free(name1);
	close(fd);
	return (1);
}
