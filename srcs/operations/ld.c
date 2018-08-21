/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:43:18 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:43:19 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	ld(t_data *data)
{
	parse_codage(data);
	if ((ARG.codage[0] != DIR_CODE &&
		ARG.codage[0] != IND_CODE) ||
		ARG.codage[1] != REG_CODE)
		return ;
	if (!(REG_INDEX(ARG.reg[1])))
		return ;
	if (ARG.codage[0] == DIR_CODE)
		REG[ARG.reg[1]] = ARG.dir[1];
	else
	{
		ARG.ind[1] %= IDX_MOD;
		memsub_src(&REG[ARG.reg[1]], &data->area, PC + ARG.ind[1], REG_SIZE);
		ft_reverse(&REG[ARG.reg[1]], REG_SIZE);
	}
	CARRY = !REG[ARG.reg[1]] ? 1 : 0;
	if (DUMP_INST)
		ft_printf("P% 5d | ld %d r%d\n", PROC_NUM, REG[ARG.reg[1]], ARG.reg[1]);
}
