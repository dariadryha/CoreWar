/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_codage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:35:04 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:35:05 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

static void		read_register(t_data *data)
{
	memsub_src(&ARG.reg[ARG.reg[0] + 1], &data->area, PC + SHIFT, T_REG);
	SHIFT += T_REG;
	ARG.reg[0]++;
}

static void		read_indirect(t_data *data)
{
	memsub_src(&ARG.ind[ARG.ind[0] + 1], &data->area, PC + SHIFT, IND_SIZE);
	ft_reverse(&ARG.ind[ARG.ind[0] + 1], IND_SIZE);
	SHIFT += IND_SIZE;
	ARG.ind[0]++;
}

static void		read_direct(t_data *data)
{
	memsub_src(&ARG.dir[ARG.dir[0] + 1], &data->area, PC + SHIFT, DIR_SIZE);
	ft_reverse(&ARG.dir[ARG.dir[0] + 1], DIR_SIZE);
	SHIFT += DIR_SIZE;
	ARG.dir[0]++;
}

static	void	*save_args(t_data *data, t_char codage)
{
	if (codage == REG_CODE)
		return (&ARG.reg[ARG.reg[0]]);
	if (codage == IND_CODE)
		return (&ARG.ind[ARG.ind[0]]);
	if (codage == DIR_CODE)
	{
		if (g_op_tab[INST].label_size == DIR_SIZE)
			return (&ARG.dir[ARG.dir[0]]);
		else
			return (&ARG.ind[ARG.ind[0]]);
	}
	return (NULL);
}

void			parse_codage(t_data *data)
{
	t_int	j[3];
	int		pos;

	ft_bzero(&j, 3 * sizeof(t_int));
	j[1] = 6;
	SHIFT += 2;
	pos = PC + 1;
	check_position(&pos);
	while (j[2] < g_op_tab[INST].num_args)
	{
		j[0] = data->area[pos] >> j[1] & 0x3;
		if (j[0] == REG_CODE)
			read_register(data);
		else if (j[0] == IND_CODE)
			read_indirect(data);
		else if (j[0] == DIR_CODE)
			g_op_tab[INST].label_size == DIR_SIZE ? DIR : IND;
		if (CODAGE(j[0]))
		{
			ARG.codage[j[2]] = j[0];
			PTR(j[2]) = save_args(data, j[0]);
		}
		j[2]++;
		j[1] -= 2;
	}
}
