/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:29:19 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/13 13:29:22 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include <ncurses.h>
# include <locale.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define TEXT_GREY COLOR_PAIR(10)
# define TEXT_RED COLOR_PAIR(2)
# define TEXT_GREEN COLOR_PAIR(1)
# define TEXT_BLUE COLOR_PAIR(3)
# define TEXT_WHITE COLOR_PAIR(5)
# define TEXT_YELLOW COLOR_PAIR(4)

# define BACKGROUND_RED COLOR_PAIR(6)
# define BACKGROUND_GREEN COLOR_PAIR(7)
# define BACKGROUND_BLUE COLOR_PAIR(8)
# define BACKGROUND_YELLOW COLOR_PAIR(9)

# define VISU_COLOR_WHITE 10
# define PLAYER_INFO_HEIGHT 4
# define CUP_LINE 20

typedef struct	s_visu
{
	WINDOW		*w_main;
	WINDOW		*w_info;
	int			pid[4];
	int			term_lines;
	int			process_alive;
	int			term_cols;
	int			cycle;
	clock_t		cl;
	clock_t		tmp;
	int			fps;
	short		pause;
	short		end;
}				t_visu;

void			draw_map(t_visu *visu, t_data *data);
void			draw_info(t_visu *visu, t_data *data);
int				run_visualizer(t_data *data, int end);
int				key_hook(t_visu *visu);
int				init_ncurses(t_visu *visualizer, t_data *data);
void			show_end_game(t_data *data, t_visu *visu);
void			draw_borders(t_visu *visualizer);
void			draw_winner(t_data *data, t_visu *visu);

#endif
