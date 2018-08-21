/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:44:14 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:44:15 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	ldi(t_data *data)
{
	int		val[3];
	int		pos;

	parse_codage(data);
	if (!(CHECK_CODAGE(ARG.codage[0])) ||
		(ARG.codage[1] != REG_CODE && ARG.codage[1] != DIR_CODE)
		|| ARG.codage[2] != REG_CODE)
		return ;
	if (VALID_INDEX(0) || VALID_INDEX(1) ||
		!(REG_INDEX(SHORT_VAL(2))))
		return ;
	val[0] = get_arg_value(data, 0);
	val[1] = get_arg_value(data, 1);
	val[2] = SHORT_VAL(2);
	pos = ((val[0] + val[1]) % IDX_MOD) + PC;
	if (DUMP_INST)
	{
		ft_printf("P% 5d | ldi %d %d r%d\n", PROC_NUM, val[0], val[1], val[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			val[0], val[1], val[0] + val[1], pos);
	}
	check_position(&pos);
	memsub_src(&REG[val[2]], &data->area, pos, REG_SIZE);
	ft_reverse(&REG[val[2]], REG_SIZE);
}
