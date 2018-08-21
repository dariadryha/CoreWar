/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <ismus@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:29:25 by ismus             #+#    #+#             */
/*   Updated: 2018/08/13 10:29:26 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_arg	*init_arg(void)
{
	t_arg *new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		return (0);
	new->arg = 0;
	new->bite = 0;
	new->size = 0;
	new->label = 0;
	return (new);
}

t_cmnd			*init_cmnd(void)
{
	t_cmnd	*new;

	if (!(new = (t_cmnd *)malloc(sizeof(t_cmnd))))
		return (0);
	new->name = 0;
	new->oper = 0;
	new->cod = 0;
	new->arg1 = init_arg();
	new->arg2 = init_arg();
	new->arg3 = init_arg();
	new->next = 0;
	new->bite = g_bite;
	return (new);
}
