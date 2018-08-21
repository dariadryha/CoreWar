/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:46:46 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:46:47 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void		live(t_data *data)
{
	int j;
	int	dir;

	j = -1;
	memsub_src(&dir, &data->area, PC + 1, DIR_SIZE);
	ft_reverse(&dir, DIR_SIZE);
	while (++j < data->quantity)
	{
		if (data->champ[j].id == dir)
		{
			data->last_live = j + 1;
			data->champ[j].last_live_cycle = PASSED_CYCLES + 1;
			data->champ[j].total_lives++;
			if ((LIVES))
				ft_printf("A process shows that player %d (%s) is alive.\n",
					INDEX + 1, data->champ[INDEX].prog_name);
		}
	}
	LIVE++;
	SHIFT += DIR_SIZE + 1;
	data->total_lives++;
	((t_proc *)(data->proc->content))->no_live = 0;
	if (DUMP_INST)
		ft_printf("P% 5d | live %d\n", PROC_NUM, dir);
}
