/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:34:22 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:34:24 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

const t_op	g_op_tab[17] =
{
	{NULL, NULL, 0, 0, 0},
	{"live", live, 10, 1, DIR_SIZE},
	{"ld", ld, 5, 2, DIR_SIZE},
	{"st", st, 5, 2, DIR_SIZE},
	{"add", add, 10, 3, DIR_SIZE},
	{"sub", sub, 10, 3, DIR_SIZE},
	{"and", ft_and, 6, 3, DIR_SIZE},
	{"or", ft_or, 6, 3, DIR_SIZE},
	{"xor", ft_xor, 6, 3, DIR_SIZE},
	{"zjmp", zjmp, 20, 1, IND_SIZE},
	{"ldi", ldi, 25, 3, IND_SIZE},
	{"sti", sti, 25, 3, IND_SIZE},
	{"fork", ft_fork, 800, 1, IND_SIZE},
	{"lld", lld, 10, 2, DIR_SIZE},
	{"lldi", lldi, 50, 3, IND_SIZE},
	{"lfork", lfork, 1000, 1, IND_SIZE},
	{"aff", aff, 2, 1, DIR_SIZE}
};
