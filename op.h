/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:28:27 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/13 13:28:28 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "corewar.h"
# include "visualizer.h"

typedef struct	s_op
{
	char		*name;
	void		(*func)(t_data *);
	short		delay;
	t_int		num_args;
	int			label_size;
}				t_op;

extern const t_op	g_op_tab[17];

#endif
