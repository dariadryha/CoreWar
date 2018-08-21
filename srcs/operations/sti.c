/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:57:55 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/13 13:57:57 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	sti(t_data *data)
{
	int	val[3];
	int	pos;

	parse_codage(data);
	if (ARG.codage[0] != REG_CODE || !(CHECK_CODAGE(ARG.codage[1])) ||
		(ARG.codage[2] != REG_CODE && ARG.codage[2] != DIR_CODE))
		return ;
	if (!(REG_INDEX(SHORT_VAL(0))) || VALID_INDEX(1) || VALID_INDEX(2))
		return ;
	val[0] = REG[SHORT_VAL(0)];
	val[1] = get_arg_value(data, 1);
	val[2] = get_arg_value(data, 2);
	pos = PC + ((val[1] + val[2]) % IDX_MOD);
	if (DUMP_INST)
	{
		ft_printf("P% 5d | sti r%d %d %d\n", PROC_NUM, SHORT_VAL(0),
			val[1], val[2], val[1], val[2], val[1] + val[2], pos);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			val[1], val[2], val[1] + val[2], pos);
	}
	check_position(&pos);
	ft_reverse(&val[0], REG_SIZE);
	memsub_dst(&data->area, &val[0], pos, REG_SIZE);
	memsub_mark(&data->area_players, ID, pos, REG_SIZE);
}
