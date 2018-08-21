/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:52:43 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:52:45 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	zjmp(t_data *data)
{
	char *str;

	memsub_src(&ARG.ind[1], &data->area, PC + 1, IND_SIZE);
	ft_reverse(&ARG.ind[1], IND_SIZE);
	if (CARRY)
	{
		SHIFT += ARG.ind[1] % IDX_MOD;
		str = OK;
	}
	else
	{
		SHIFT += IND_SIZE + 1;
		str = FAIL;
	}
	if (DUMP_INST)
		ft_printf("P% 5d | zjmp %d %s\n", PROC_NUM, ARG.ind[1], str);
}
