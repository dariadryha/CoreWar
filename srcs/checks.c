/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:15:30 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:15:36 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static	void	process_lives(t_data *data)
{
	t_list	*temp;

	ft_lstdelif(data);
	temp = data->proc;
	while (temp)
	{
		(*(t_proc *)temp->content).live = 0;
		temp = temp->next;
	}
}

void			set_to_zero(t_data *data)
{
	int j;

	j = -1;
	while (++j < data->quantity)
		data->champ[j].total_lives = 0;
	process_lives(data);
}

int				check_lives(t_data *data)
{
	if (!data->total_lives)
		return (1);
	set_to_zero(data);
	if (data->total_lives >= NBR_LIVE)
		data->cycle_to_die -= CYCLE_DELTA;
	data->total_lives = 0;
	(data->check_cycle)++;
	return (0);
}

void			check_cycle(t_data *data)
{
	static int cycle;

	if (!cycle)
		cycle = CYCLE_TO_DIE;
	if (data->cycle_to_die == cycle)
	{
		if (data->check_cycle == MAX_CHECKS)
		{
			data->cycle_to_die -= CYCLE_DELTA;
			data->check_cycle = 0;
			cycle = data->cycle_to_die;
		}
	}
	else
	{
		data->check_cycle = 0;
		cycle = data->cycle_to_die;
	}
}

void			check_position(int *pos)
{
	*pos %= MEM_SIZE;
	if (*pos < 0)
		*pos += MEM_SIZE;
}
