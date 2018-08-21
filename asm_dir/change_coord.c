/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:21:51 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:21:55 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	find_coord(char *name, t_cmnd *cmnd)
{
	while (cmnd)
	{
		if (cmnd->name && ft_strcmp(name, cmnd->name) == 0)
			return (cmnd->bite);
		cmnd = cmnd->next;
	}
	ft_printf("Not found a label %s\n", name);
	return (-1);
}

static int	arg2_3(t_cmnd *copy, t_cmnd *cmnd, int i)
{
	if (copy->arg2->label != 0)
	{
		i = find_coord(copy->arg2->label, cmnd);
		if (i < 0)
			return (-1);
		copy->arg2->arg = i - copy->bite;
	}
	if (copy->arg3->label != 0)
	{
		i = find_coord(copy->arg3->label, cmnd);
		if (i < 0)
			return (-1);
		copy->arg3->arg = i - copy->bite;
	}
	return (1);
}

int			change_coord(t_cmnd *cmnd)
{
	t_cmnd	*copy;
	int		i;
	int		n;

	copy = cmnd;
	while (copy)
	{
		if (copy->arg1->label != 0)
		{
			i = find_coord(copy->arg1->label, cmnd);
			if (i < 0)
				return (-1);
			copy->arg1->arg = i - copy->bite;
		}
		if (arg2_3(copy, cmnd, i) < 0)
			return (-1);
		copy = copy->next;
	}
	return (1);
}
