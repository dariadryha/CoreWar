/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:29:24 by vshkykav          #+#    #+#             */
/*   Updated: 2018/08/13 19:29:26 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../op.h"

void	skip_visu(t_visu *visu)
{
	wclear(visu->w_main);
	wattron(visu->w_main, TEXT_YELLOW);
	mvwprintw(visu->w_main, 30, 80, "Waiting for winner...");
	draw_borders(visu);
	wrefresh(visu->w_main);
}

int		key_hook(t_visu *visu)
{
	int	key;

	key = getch();
	if (key == 10 && !visu->end)
	{
		skip_visu(visu);
		return (2);
	}
	if (key == 32)
	{
		visu->pause = (visu->pause) ? 0 : 1;
		return (0);
	}
	if (key == 27)
	{
		endwin();
		return (-1);
	}
	if (key == 78 || key == 45)
		if (visu->fps > 1)
			visu->fps -= 1;
	if (key == 69 || key == 43)
		if (visu->fps < 200)
			visu->fps += 1;
	return (1);
}
