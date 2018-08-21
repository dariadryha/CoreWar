/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:19:12 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:19:15 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_error(char *str1, char *str2)
{
	if (str2)
		ft_printf("%e%s %s\n", str1, str2);
	else
		ft_printf("%e%s\n", str1);
	exit(1);
}

void	ft_struct_file(char *str1, char *str2)
{
	ft_printf("%eError: File %s %s\n", str2, str1);
	exit(1);
}

void	ft_large(t_int arg1, char *str)
{
	ft_printf("%eError: File %s %s (%d bytes > %d bytes)\n",
		str, LARGE_PROG, arg1, CHAMP_MAX_SIZE);
	exit(1);
}

void	ft_usage(void)
{
	ft_printf("Usage: ./corewar [-dump N | [[-n number] champion1.cor]");
	ft_printf(" <...>] [-a | -v | -o | -m | -d | -l] <champion1.cor> <...>\n");
	ft_printf("-dump N   : Dumps memory after N cycles then exits\n");
	ft_printf("-n N      : Sets the number of the next player\n");
	ft_printf("-a        : Prints output from \"aff\" (Default");
	ft_printf(" is to hide it)\n-v        : Ncurses output mode\n");
	ft_printf("-o        : Show operations (Params are NOT litteral ...)\n");
	ft_printf("-m        : Show PC movements (Except for jumps)\n");
	ft_printf("-d        : Show deaths\n");
	ft_printf("-l        : Show lives\n");
	exit(1);
}
