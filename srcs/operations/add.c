/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:39:24 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:39:26 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	add(t_data *data)
{
	parse_codage(data);
	if (!(REG_INDEX(ARG.reg[1])) ||
		!(REG_INDEX(ARG.reg[2])) ||
		!(REG_INDEX(ARG.reg[3])))
		return ;
	REG[ARG.reg[3]] = REG[ARG.reg[1]] +
	REG[ARG.reg[2]];
	CARRY = !REG[ARG.reg[3]] ? 1 : 0;
	if (DUMP_INST)
		ft_printf("P% 5d | add r%d r%d r%d\n",
			PROC_NUM, ARG.reg[1], ARG.reg[2], ARG.reg[3]);
}
