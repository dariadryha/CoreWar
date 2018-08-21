/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:41:42 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:41:43 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	ft_fork(t_data *data)
{
	int		pos;

	memsub_src(&ARG.ind[1], &data->area, PC + 1, IND_SIZE);
	ft_reverse(&ARG.ind[1], IND_SIZE);
	pos = PC + ARG.ind[1] % IDX_MOD;
	if (DUMP_INST)
		ft_printf("P% 5d | fork %d (%d)\n", PROC_NUM, ARG.ind[1], pos);
	check_position(&pos);
	new_process(data, pos);
	SHIFT += IND_SIZE + 1;
}
