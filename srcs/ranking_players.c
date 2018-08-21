/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:31:37 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/13 13:31:38 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static	void	init_process(t_data *data, int index, int pc)
{
	t_proc	process;

	ft_bzero(&process, sizeof(t_proc));
	process.reg[1] = data->champ[index].id;
	process.index = index;
	process.id = data->champ[index].id;
	process.pc = pc;
	process.num = data->num++;
	ft_lstadd(&data->proc, ft_lstnew(&process, sizeof(t_proc)));
}

void			mark_player_area(t_data *data, int start, int champ_id)
{
	t_int	i;

	i = 0;
	while (i < data->champ[champ_id].prog_size)
	{
		if (start + i > MEM_SIZE)
			break ;
		data->area_players[start + i] = data->champ[champ_id].id;
		i++;
	}
}

void			ranking_players(t_data *data)
{
	int i;
	int j;
	int	pos;

	i = -1;
	j = 0;
	pos = MEM_SIZE / data->quantity;
	while (++i < data->quantity)
	{
		ft_memcpy(&data->area[j], data->champ[i].code,
			data->champ[i].prog_size);
		mark_player_area(data, j, i);
		init_process(data, i, j);
		j += pos;
	}
}
