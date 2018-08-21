/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:17:40 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:17:43 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

static	void	move_process(t_data *data)
{
	((t_proc *)(data->proc->content))->no_live++;
	if (!DELAY && OP_CODE(PC))
	{
		DELAY = g_op_tab[data->area[PC]].delay;
		INST = data->area[PC];
	}
	if (DELAY)
	{
		DELAY--;
		if (!DELAY)
		{
			g_op_tab[INST].func(data);
			if (PC_MOVE)
				pc_movements(data);
			PC += SHIFT;
			ft_bzero(&ARG, sizeof(t_arg));
		}
	}
	else
		PC++;
}

static	void	move_players(t_data *data)
{
	t_list		*temp;
	uintmax_t	num;

	temp = data->proc;
	num = ft_lstlen(temp);
	while (num--)
	{
		move_process(data);
		check_position(&PC);
		if (!num && data->proc->next)
			add_to_begin(&temp, &data->proc);
		data->proc = data->proc->next;
	}
	data->proc = temp;
}

void			visu(t_data *data)
{
	static	int key = 0;

	if (key != 2 && VISUAL)
	{
		key = run_visualizer(data, 0);
		if (key == -1)
			exit(1);
	}
}

void			start_infernal_game(t_data *data)
{
	visu(data);
	while (data->cycle_to_die > 0)
	{
		if (DUMP_MEMORY(PASSED_CYCLES))
			dump_memory(data);
		move_players(data);
		data->passed_cycles[0]++;
		if (!(data->passed_cycles[0] % data->cycle_to_die))
		{
			if (check_lives(data))
				return ;
			check_cycle(data);
			data->passed_cycles[1] += data->passed_cycles[0];
			data->passed_cycles[0] = 0;
		}
		visu(data);
	}
	move_players(data);
}
