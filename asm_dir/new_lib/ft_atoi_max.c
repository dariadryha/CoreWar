/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:50:46 by ismus             #+#    #+#             */
/*   Updated: 2017/10/25 15:24:50 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t			ft_atoi_max(const char *str)
{
	intmax_t	i;
	int			flag;
	intmax_t	a;

	i = 0;
	a = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == '\f' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
		a = str[i++] - '0' + a * 10;
	return (flag == -1 ? -a : a);
}
