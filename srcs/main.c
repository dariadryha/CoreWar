/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:11:51 by ddryha            #+#    #+#             */
/*   Updated: 2018/07/05 15:11:54 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"
#include "../visualizer.h"

int		main(int argc, char **argv)
{
	t_data data;

	ft_bzero(&data, sizeof(data));
	parse_arguments(&data, argc - 1, &argv[1]);
	ranking_players(&data);
	announcement_of_players(&data);
	start_infernal_game(&data);
	free_data(&data);
	visu(&data);
	announcement_of_winner(&data);
	return (0);
}
