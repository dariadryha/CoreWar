/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:49:00 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:49:01 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

void	ft_or(t_data *data)
{
	int val[3];

	parse_codage(data);
	if (!(CHECK_CODAGE(ARG.codage[0])) ||
		!(CHECK_CODAGE(ARG.codage[1])) || ARG.codage[2] != REG_CODE)
		return ;
	if (VALID_INDEX(0) || VALID_INDEX(1) ||
		!(REG_INDEX(SHORT_VAL(2))))
		return ;
	val[0] = get_arg_value(data, 0);
	val[1] = get_arg_value(data, 1);
	val[2] = SHORT_VAL(2);
	REG[val[2]] = val[0] | val[1];
	CARRY = !REG[val[2]] ? 1 : 0;
	if (DUMP_INST)
		ft_printf("P% 5d | or %d %d r%d\n", PROC_NUM, val[0], val[1], val[2]);
}
