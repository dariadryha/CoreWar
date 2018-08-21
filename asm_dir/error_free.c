/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:30:03 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:30:03 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			error_name_com(int n, int i, char *str)
{
	if (n == 0 && i > PROG_NAME_LENGTH)
	{
		free(str);
		return (ret_err("Name too long"));
	}
	if (n == 1 && i > COMMENT_LENGTH)
	{
		free(str);
		return (ret_err("Comment too long"));
	}
	return (1);
}

void		error(char *line)
{
	ft_printf("%s\n", line);
	exit(0);
}

int			ret_err(char *line)
{
	ft_printf("%s\n", line);
	return (-1);
}

int			err_line(char *line)
{
	ft_printf("%s%i\n", line, g_file);
	return (-1);
}
