/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:36:30 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:36:31 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static	void	check_pre_flags(t_data *data, int n)
{
	int j;

	j = -1;
	if (n == 1)
		return ;
	while (++j < FLGS)
	{
		if (data->flg[j][0] && j != n && j != 1)
			ft_usage();
	}
}

static int		search_flg(char *str)
{
	if (ft_strequ(str, "-dump"))
		return (1);
	else if (ft_strequ(str, "-n"))
		return (2);
	else if (ft_strequ(str, "-v"))
		return (3);
	else if (ft_strequ(str, "-a"))
		return (4);
	else if (ft_strequ(str, "-o"))
		return (5);
	else if (ft_strequ(str, "-m"))
		return (6);
	else if (ft_strequ(str, "-d"))
		return (7);
	else if (ft_strequ(str, "-l"))
		return (8);
	else
		return (0);
}

static int		get_flg_value(char *str)
{
	int res;

	if (!str)
		ft_usage();
	if (!ft_str_digit(str))
		ft_usage();
	res = ft_atoi(str);
	return (res);
}

int				check_arguments(t_data *data, char **str)
{
	int count;
	int n;

	count = 0;
	while ((n = search_flg(str[count])))
	{
		n -= 1;
		check_pre_flags(data, n);
		if (!n || n == 1)
			data->flg[n][1] = get_flg_value(str[count + 1]);
		data->flg[n][0] = 1;
		count += !n || n == 1 ? 2 : 1;
	}
	return (count);
}

void			parse_flags(t_data *data, int argc, char **argv)
{
	int id;
	int count[3];

	ft_bzero(&count, sizeof(int) * 3);
	while (count[1] + count[0] < argc)
	{
		count[0] += check_arguments(data, &argv[count[1] + count[0]]);
		count[1] == MAX_ARGS_NUMBER ? MANY_ARGS : 0;
		if (SET_ID)
		{
			id = data->flg[1][1]++;
			data->champ[count[1]].id = id;
		}
		count[1]++;
	}
}
