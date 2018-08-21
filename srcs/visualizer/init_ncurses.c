/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:29:12 by vshkykav          #+#    #+#             */
/*   Updated: 2018/08/13 19:29:16 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../op.h"

void	init_players_id(t_visu *visualizer, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->quantity)
	{
		visualizer->pid[i] = data->champ[i].id;
	}
}

void	init_colors(void)
{
	init_color(VISU_COLOR_WHITE, 1000, 1000, 1000);
	init_pair(11, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, VISU_COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_BLACK, COLOR_GREEN);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
}

int		init_ncurses(t_visu *visualizer, t_data *data)
{
	if (!initscr())
	{
		fprintf(stderr, "Can't initialize ncurses.\n");
		exit(1);
	}
	noecho();
	keypad(stdscr, TRUE);
	cbreak();
	start_color();
	curs_set(0);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	init_colors();
	refresh();
	init_players_id(visualizer, data);
	visualizer->w_main = newwin(4 + (MEM_SIZE / 64), 197, 0, 0);
	visualizer->w_info = newwin(4 + (MEM_SIZE / 64), 55, 0, 196);
	visualizer->pause = 1;
	visualizer->cycle = -1;
	visualizer->cl = clock();
	visualizer->fps = 50;
	visualizer->end = 0;
	getmaxyx(stdscr, visualizer->term_cols, visualizer->term_lines);
	return (1);
}
