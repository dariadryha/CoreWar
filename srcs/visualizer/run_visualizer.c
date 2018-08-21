/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_visualizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:29:33 by vshkykav          #+#    #+#             */
/*   Updated: 2018/08/13 19:29:35 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../op.h"

void	draw_borders(t_visu *visualizer)
{
	wattron(visualizer->w_main, COLOR_PAIR(11));
	box(visualizer->w_main, ' ', ' ');
	wattron(visualizer->w_info, COLOR_PAIR(11));
	box(visualizer->w_info, ' ', ' ');
}

int		delay_game(t_visu *visu, clock_t delta_ticks)
{
	clock_t		delay;
	int			key;

	delay = (CLOCKS_PER_SEC / visu->fps - delta_ticks) / 1000;
	if (delay > 2000)
		delay = CLOCKS_PER_SEC / (1000 * visu->fps);
	while (delay > 5)
	{
		delay -= 1;
		usleep(1000);
		key = key_hook(visu);
		if (key == -1 || key == 2)
			return (key);
	}
	return (0);
}

int		pause_game(t_visu *visu, t_data *data)
{
	int key;

	if (visu->pause)
	{
		while (1)
		{
			visu->cl = clock();
			key = key_hook(visu);
			if (!key)
				break ;
			if (key == -1)
				return (-1);
			if (key == 2)
				return (2);
			draw_info(visu, data);
			wrefresh(visu->w_info);
		}
	}
	return (0);
}

void	draw_game(t_visu *visu, t_data *data)
{
	draw_map(visu, data);
	draw_info(visu, data);
	draw_borders(visu);
	wrefresh(visu->w_main);
	wrefresh(visu->w_info);
}

int		run_visualizer(t_data *data, int end)
{
	static t_visu	visualizer;
	static int		initialized = 0;
	int				key;
	clock_t			delta_ticks;

	setlocale(LC_ALL, "");
	if (!initialized)
		initialized = init_ncurses(&visualizer, data);
	if (end)
		show_end_game(data, &visualizer);
	else
	{
		visualizer.cycle++;
		delta_ticks = clock() - visualizer.cl;
		visualizer.cl = clock();
		draw_game(&visualizer, data);
		key = pause_game(&visualizer, data);
		if (key == -1 || key == 2)
			return (key);
		key = delay_game(&visualizer, delta_ticks);
		if (key == -1 || key == 2)
			return (key);
	}
	key = key_hook(&visualizer);
	return (key);
}
