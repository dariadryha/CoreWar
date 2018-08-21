/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_end_game_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:29:42 by vshkykav          #+#    #+#             */
/*   Updated: 2018/08/13 19:29:44 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../op.h"

void	draw_cup_3(t_visu *visu)
{
	mvwprintw(visu->w_main, CUP_LINE + 20, 10,
		"               $$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 21, 10,
		"            $$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 22, 10,
		"            $$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 26, 10,
		"            $$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 27, 10,
		"            $$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 28, 10,
		"          $$$$$$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 29, 10,
		"         $$$$$$$$$$$$$$$$$$$$$$$$");
}

void	draw_cup_2(t_visu *visu)
{
	mvwprintw(visu->w_main, CUP_LINE + 9, 10,
		" $$$   $$$ $$$$$$$$$$$$$$$$$$$$ $$$    $$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 10, 10,
		" $$$$   $$$ $$$$$$$$$$$$$$$$$$ $$$$  $$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 11, 10,
		"   $$$$  $$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 12, 10,
		"    $$$$$$$$ $$$$$$$$$$$$$$$$ $$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 13, 10,
		"      $$$$$$  $$$$$$$$$$$$$$   $$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 14, 10,
		"               $$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 15, 10,
		"                 $$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 16, 10,
		"                   $$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 17, 10,
		"                   $$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 18, 10,
		"                   $$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 19, 10,
		"                   $$$$ ");
	draw_cup_3(visu);
}

void	draw_cup_1(t_visu *visu)
{
	mvwprintw(visu->w_main, CUP_LINE, 10,
		"        $$$$$$$$$$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 1, 10,
		"        $$$$$$$$$$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 2, 10,
		"   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 3, 10,
		" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 4, 10,
		"$$$$      $$$$$$$$$$$$$$$$$$$$$$       $$$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 5, 10,
		"$$$       $$$$$$$$$$$$$$$$$$$$$$        $$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 6, 10,
		"$$        $$$$$$$$$$$$$$$$$$$$$$        $$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 7, 10,
		"$$$     $$$$$$$$$$$$$$$$$$$$$$$$$$      $$$ ");
	mvwprintw(visu->w_main, CUP_LINE + 8, 10,
		"$$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$    $$$$ ");
	draw_cup_2(visu);
}

int		draw_winner_pos(t_data *data, int index)
{
	int	i;
	int	start;

	i = 0;
	start = 28;
	while (i < PROG_NAME_LENGTH && data->champ[index].prog_name[i])
		i++;
	i /= 2;
	start -= i;
	if (start < 10)
		start = 10;
	return (start);
}

void	draw_winner(t_data *data, t_visu *visu)
{
	int	i;
	int	start;
	int index;

	index = !(data->last_live) ? data->quantity - 1 : data->last_live - 1;
	start = draw_winner_pos(data, index);
	i = -1;
	mvwprintw(visu->w_main, CUP_LINE + 23, start, "╭─");
	mvwprintw(visu->w_main, CUP_LINE + 24, start, "| ");
	mvwprintw(visu->w_main, CUP_LINE + 25, start, "╰─");
	start += 2;
	while (++i < PROG_NAME_LENGTH && data->champ[index].prog_name[i])
	{
		mvwprintw(visu->w_main, CUP_LINE + 23, start + i, "━");
		mvwprintw(visu->w_main, CUP_LINE + 24, start + i, "%c",
			data->champ[index].prog_name[i]);
		mvwprintw(visu->w_main, CUP_LINE + 25, start + i, "━");
	}
	mvwprintw(visu->w_main, CUP_LINE + 23, start + i, "─╮");
	mvwprintw(visu->w_main, CUP_LINE + 24, start + i, " |");
	mvwprintw(visu->w_main, CUP_LINE + 25, start + i, "─╯");
	draw_cup_1(visu);
}
