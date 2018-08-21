/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:28:37 by vshkykav          #+#    #+#             */
/*   Updated: 2018/08/19 13:13:38 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../op.h"

void	draw_player_info(t_visu *visu, t_data *data)
{
	int i;

	i = -1;
	while (++i < data->quantity)
	{
		wattron(visu->w_info, COLOR_PAIR(i + 1));
		mvwprintw(visu->w_info, i * PLAYER_INFO_HEIGHT + 9, 3,
			"Player %d: %.39s",
			data->champ[i].id, data->champ[i].prog_name);
		wattroff(visu->w_info, TEXT_GREEN);
		wattron(visu->w_info, TEXT_WHITE);
		mvwprintw(visu->w_info, i * PLAYER_INFO_HEIGHT + 10, 3, "Lives: %-10d",
			data->champ[i].total_lives);
		mvwprintw(visu->w_info, i * PLAYER_INFO_HEIGHT + 11, 3,
			"Last live cycle: %d", data->champ[i].last_live_cycle);
	}
}

void	draw_info_2(t_visu *visu, t_data *data)
{
	wattron(visu->w_info, TEXT_WHITE);
	mvwprintw(visu->w_info, 4, 3, "Cycles/second limit: %3d", visu->fps);
	mvwprintw(visu->w_info, 6, 3, "Cycle: %-10d", visu->cycle);
	mvwprintw(visu->w_info, 7, 3, "Processes: %-5d", visu->process_alive);
	draw_player_info(visu, data);
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 10, 3,
		"CYCLE_TO_DIE: %-10d", data->cycle_to_die);
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 11, 3,
		"CYCLE_DELTA: %-10d", CYCLE_DELTA);
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 12, 3,
		"NBR_LIVE: %-10d", NBR_LIVE);
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 13, 3,
		"MAX_CHECKS: %-10d", MAX_CHECKS);
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 16, 3,
		"    CONTROLS");
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 18, 3,
		"(space) | pause/run game");
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 19, 3,
		" (esc)  | exit");
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 20, 3,
		"(enter) | skip map visualization");
	mvwprintw(visu->w_info, data->quantity * PLAYER_INFO_HEIGHT + 21, 3,
		"  +/-   | increase/decrease speed");
}

void	draw_info(t_visu *visu, t_data *data)
{
	if (visu->pause)
	{
		wattron(visu->w_info, TEXT_RED);
		mvwprintw(visu->w_info, 2, 3, "%-15s", "<< PAUSE >>");
	}
	else
	{
		wattron(visu->w_info, TEXT_GREEN);
		mvwprintw(visu->w_info, 2, 3, "%-15s", "<< RUNNING >>");
	}
	draw_info_2(visu, data);
}
