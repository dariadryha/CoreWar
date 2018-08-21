/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:28:48 by vshkykav          #+#    #+#             */
/*   Updated: 2018/08/13 19:28:50 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../op.h"

void	select_color_2(t_visu *visu, t_data *data, int i)
{
	if (data->quantity >= 3)
	{
		if (data->area_players[i] == visu->pid[2])
			wattron(visu->w_main, TEXT_BLUE);
		if (data->area_players[i] == 30)
			wattron(visu->w_main, BACKGROUND_BLUE);
	}
	if (data->quantity >= 4)
	{
		if (data->area_players[i] == visu->pid[3])
			wattron(visu->w_main, TEXT_YELLOW);
		if (data->area_players[i] == 40)
			wattron(visu->w_main, BACKGROUND_YELLOW);
	}
}

void	select_color(t_visu *visu, t_data *data, int i)
{
	wattron(visu->w_main, TEXT_GREY);
	if (data->area_players[i] == visu->pid[0])
		wattron(visu->w_main, TEXT_GREEN);
	if (data->area_players[i] == 10)
		wattron(visu->w_main, BACKGROUND_GREEN);
	if (data->quantity >= 2)
	{
		if (data->area_players[i] == visu->pid[1])
			wattron(visu->w_main, TEXT_RED);
		if (data->area_players[i] == 20)
			wattron(visu->w_main, BACKGROUND_RED);
	}
	select_color_2(visu, data, i);
}

void	select_color_process(t_visu *visu, t_data *data, int id)
{
	if (id == visu->pid[0])
		wattron(visu->w_main, TEXT_GREEN);
	if (data->quantity >= 2 && id == visu->pid[1])
		wattron(visu->w_main, TEXT_RED);
	if (data->quantity >= 3 && id == visu->pid[2])
		wattron(visu->w_main, TEXT_BLUE);
	if (data->quantity == 4 && id == visu->pid[3])
		wattron(visu->w_main, TEXT_YELLOW);
}

void	mark_process(t_visu *visu, t_data *data)
{
	t_list	*temp;
	int		pc;

	visu->process_alive = 0;
	temp = data->proc;
	while (temp)
	{
		visu->process_alive++;
		{
			pc = ((t_proc *)temp->content)->pc;
			wmove(visu->w_main, (int)(pc / 64), (int)(pc % 64));
			wattron(visu->w_main, A_REVERSE);
			select_color_process(visu, data, ((t_proc *)temp->content)->id);
			mvwprintw(visu->w_main, (2 + (int)(pc / 64)),
				3 + ((int)(pc % 64) * 3), "%02x", data->area[pc]);
			wattroff(visu->w_main, A_REVERSE);
		}
		temp = temp->next;
	}
}

void	draw_map(t_visu *visu, t_data *data)
{
	int col;
	int row;
	int i;

	i = -1;
	col = 0;
	row = 0;
	while (++i < MEM_SIZE)
	{
		if (i > 0 && i % 64 == 0)
		{
			row++;
			col = 0;
		}
		select_color(visu, data, i);
		mvwprintw(visu->w_main, (2 + row), 3 + (col * 3),
			"%02x", data->area[i]);
		col++;
	}
	mark_process(visu, data);
}
