/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:58:21 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/13 13:58:22 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	st(t_data *data)
{
	int val;

	parse_codage(data);
	if (ARG.codage[0] != REG_CODE || (ARG.codage[1] != REG_CODE &&
		ARG.codage[1] != IND_CODE) || !(REG_INDEX(ARG.reg[1])))
		return ;
	if (ARG.codage[1] == REG_CODE)
	{
		if (!(REG_INDEX(ARG.reg[2])))
			return ;
		REG[ARG.reg[2]] = REG[ARG.reg[1]];
		val = ARG.reg[2];
	}
	else
	{
		ft_reverse(&REG[ARG.reg[1]], REG_SIZE);
		val = ARG.ind[1];
		memsub_dst(&data->area, &REG[ARG.reg[1]],
			PC + ARG.ind[1] % IDX_MOD, REG_SIZE);
		memsub_mark(&data->area_players, ID,
			PC + ARG.ind[1] % IDX_MOD, REG_SIZE);
		ft_reverse(&REG[ARG.reg[1]], REG_SIZE);
	}
	if (DUMP_INST)
		ft_printf("P% 5d | st r%d %d\n", PROC_NUM, ARG.reg[1], val);
}
