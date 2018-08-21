/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_end_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:29:42 by vshkykav          #+#    #+#             */
/*   Updated: 2018/08/13 19:29:44 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../op.h"

void	draw_4(t_visu *visu)
{
	mvwprintw(visu->w_main, 50, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 51, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 52, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 53, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 54, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 55, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 56, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 57, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 58, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 59, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 60, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 61, 130, "                          ($$$^$$$)");
	mvwprintw(visu->w_main, 62, 130, "                          ($$$^$$$)");
	mvwprintw(visu->w_main, 63, 130, "                          ($$$^$$$)");
	mvwprintw(visu->w_main, 64, 130, "                           ($$^$$)");
	mvwprintw(visu->w_main, 65, 130, "                           ($$^$$)");
	mvwprintw(visu->w_main, 66, 130, "                           ($$^$$)");
	mvwprintw(visu->w_main, 67, 130, "                            ($^$)");
	mvwprintw(visu->w_main, 68, 130, "                            ($^$)");
	mvwprintw(visu->w_main, 69, 130, "                            ($$$)");
	mvwprintw(visu->w_main, 70, 130, "                             ($)");
}

void	draw_3(t_visu *visu)
{
	mvwprintw(visu->w_main, 26, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 27, 130, "                          ($$$^$$$)");
	mvwprintw(visu->w_main, 28, 130, "                       ($  $$$^$$$  $)");
	mvwprintw(visu->w_main, 29, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 30, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 31, 133, "                 ($    ($$$^$$$)    $)");
	mvwprintw(visu->w_main, 32, 133, "                 ($$    $$$^$$$    $$)");
	mvwprintw(visu->w_main, 33, 133, "                  ($$$$$$$$^$$$$$$$$)");
	mvwprintw(visu->w_main, 34, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 35, 130, "                          ($$$^$$$)");
	mvwprintw(visu->w_main, 36, 130, "                         ($$$$^$$$$)");
	mvwprintw(visu->w_main, 37, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 38, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 39, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 40, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 41, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 42, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 43, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 44, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 45, 130, "                       ($$$$$$^$$$$$$)");
	mvwprintw(visu->w_main, 46, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 47, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 48, 130, "                        ($$$$$^$$$$$)");
	mvwprintw(visu->w_main, 49, 130, "                        ($$$$$^$$$$$)");
	draw_4(visu);
}

void	draw_2(t_visu *visu)
{
	mvwprintw(visu->w_main, 14, 130,
		"      ($$$$$)            ($$$$$$$$$)            ($$$$$)      ");
	mvwprintw(visu->w_main, 15, 130,
		"        ($$$$$$$)      ($$$$$$$$$$$$$)      ($$$$$$$)        ");
	mvwprintw(visu->w_main, 16, 130,
		"      ($$$$$$$$$$$$$$$$$$$$$$$_$$$$$$$$$$$$$$$$$$$$$$$)      ");
	mvwprintw(visu->w_main, 17, 130,
		"            ($$$$$$$$$$$$$$$$  _$$$$$$$$$$$$$$$$)            ");
	mvwprintw(visu->w_main, 18, 130,
		"       ($$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$)      ");
	mvwprintw(visu->w_main, 19, 130,
		"                     ($$$$$$$$$$$$$$$$$)                     ");
	mvwprintw(visu->w_main, 20, 130,
		"                          ($$$$$$$)                          ");
	mvwprintw(visu->w_main, 21, 130,
		"                        ($$$$$$$$$$$)                        ");
	mvwprintw(visu->w_main, 22, 130,
		"                       ($$$       $$$)                       ");
	mvwprintw(visu->w_main, 23, 130,
		"                        ($$$     $$$)                        ");
	mvwprintw(visu->w_main, 24, 130,
		"                     ($    $$$ $$$    $)                     ");
	mvwprintw(visu->w_main, 25, 130,
		"                      ($$$$$$$^$$$$$$$)                      ");
	draw_3(visu);
}

void	draw_1(t_visu *visu)
{
	mvwprintw(visu->w_main, 2, 130,
	"                        ($$$$$$$$$)                          ");
	mvwprintw(visu->w_main, 3, 130,
	"                         ($$$$$$$)                           ");
	mvwprintw(visu->w_main, 4, 130,
	"                       ($$$$$$$$$$$)                         ");
	mvwprintw(visu->w_main, 5, 130,
	"                          ($$$$$)                            ");
	mvwprintw(visu->w_main, 6, 130,
	"     ($)                   ($$$$$)                   ($)     ");
	mvwprintw(visu->w_main, 7, 130,
	"    ($$)                   ($$$$$)                   ($$)    ");
	mvwprintw(visu->w_main, 8, 130,
	"   ($$)                    ($$$$$)                    ($$)   ");
	mvwprintw(visu->w_main, 9, 130,
	"  ($$)                     ($$$$$)                     ($$)  ");
	mvwprintw(visu->w_main, 10, 130,
	"  ($$$)                    ($$$$$)                    ($$$)  ");
	mvwprintw(visu->w_main, 11, 130,
	"   ($$$$)                  ($$$$$)                  ($$$$)   ");
	mvwprintw(visu->w_main, 12, 130,
	"    ($$$$$)                ($$$$$)                ($$$$$)    ");
	mvwprintw(visu->w_main, 13, 130,
	"     ($$$$$)               ($$$$$)               ($$$$$)     ");
	draw_2(visu);
}

void	show_end_game(t_data *data, t_visu *visu)
{
	int index;
	int key;

	visu->end = 1;
	index = !(data->last_live) ? data->quantity - 1 : data->last_live - 1;
	wclear(visu->w_main);
	while (1)
	{
		wattron(visu->w_main, TEXT_WHITE);
		mvwprintw(visu->w_main, 8, 20, "%s", data->champ[index].comment);
		draw_1(visu);
		draw_winner(data, visu);
		draw_borders(visu);
		wrefresh(visu->w_main);
		key = key_hook(visu);
		if (key == -1)
			return ;
	}
}
