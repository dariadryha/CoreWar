/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:16:26 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:16:31 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
#include "../visualizer.h"

void	ft_reverse(void *temp, int x)
{
	int		i[2];
	char	c;

	i[0] = 0;
	i[1] = x - 1;
	while (i[0] < i[1])
	{
		c = ((char *)temp)[i[0]];
		((char *)temp)[i[0]++] = ((char *)temp)[i[1]];
		((char *)temp)[i[1]--] = c;
	}
}

void	dump_memory(t_data *data)
{
	int k;

	k = 0;
	while (k < MEM_SIZE)
	{
		if (k == 0)
			ft_printf("0x0000 : ");
		ft_printf("%02hhx ", data->area[k]);
		if (!((k + 1) % 64))
		{
			ft_printf("\n");
			if (k + 1 != MEM_SIZE)
				ft_printf("%#06x : ", k + 1);
		}
		k++;
	}
	exit(1);
}

void	pc_movements(t_data *data)
{
	int j;
	int pos;

	j = -1;
	if (INST == 9 && CARRY)
		return ;
	!PC ? ft_printf("ADV %d (0x0000 -> %#06x) ", SHIFT, PC + SHIFT) :
	ft_printf("ADV %d (%#06x -> %#06x) ", SHIFT, PC, PC + SHIFT);
	pos = PC;
	while (++j < SHIFT)
	{
		check_position(&pos);
		ft_printf("%02x ", data->area[pos]);
		pos++;
	}
	ft_printf("\n");
}

void	announcement_of_winner(t_data *data)
{
	int index;

	index = !data->last_live ? data->quantity - 1 : data->last_live - 1;
	if (VISUAL)
		run_visualizer(data, 1);
	else
		ft_printf("Contestant %d, \"%s\", has won !\n",
			index + 1, data->champ[index].prog_name);
}

void	announcement_of_players(t_data *data)
{
	int j;

	j = -1;
	if (VISUAL)
		return ;
	ft_printf("Introducing contestants...\n");
	while (++j < data->quantity)
	{
		ft_printf("* Player %d, weighing %d bytes, ",
			j + 1, data->champ[j].prog_size);
		ft_printf("\"%s\" (\"%s\") !\n",
			data->champ[j].prog_name, data->champ[j].comment);
	}
}
