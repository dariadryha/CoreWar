/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:20:50 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:20:53 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../op.h"

t_int	get_arg_value(t_data *data, int num)
{
	t_int	res;
	int		pos;

	res = 0;
	if (ARG.codage[num] == REG_CODE)
		res = REG[SHORT_VAL(num)];
	else if (ARG.codage[num] == IND_CODE)
	{
		pos = PC + (SHORT_VAL(num) % IDX_MOD);
		check_position(&pos);
		memsub_src(&res, &data->area, pos, T_IND);
		ft_reverse(&res, T_IND);
	}
	else if (ARG.codage[num] == DIR_CODE)
		res = g_op_tab[INST].label_size == IND_SIZE ?
	SHORT_VAL(num) : T_INT_VAL(num);
	return (res);
}

void	new_process(t_data *data, int pc)
{
	t_list *temp;
	t_proc new;

	temp = data->proc;
	ft_memcpy(&new, (t_proc *)data->proc->content, sizeof(t_proc));
	new.pc = pc;
	new.num = data->num++;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_lstnew(&new, sizeof(t_proc));
}

void	memsub_src(void *dst, const void *src, int start, size_t len)
{
	size_t j;

	j = -1;
	while (++j < len)
	{
		check_position(&start);
		((char *)dst)[j] = ((const char *)src)[start];
		start++;
	}
}

void	memsub_dst(void *dst, const void *src, int start, size_t len)
{
	size_t j;

	j = -1;
	while (++j < len)
	{
		check_position(&start);
		((char *)dst)[start] = ((const char *)src)[j];
		start++;
	}
}

void	memsub_mark(void *dst, int index, int start, size_t len)
{
	size_t j;

	j = -1;
	while (++j < len)
	{
		check_position(&start);
		((int *)dst)[start] = index;
		start++;
	}
}
