/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:34:48 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:34:50 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static	void	read_exec_code(int fd, t_play *champ, char *argv)
{
	ssize_t	res[2];

	ft_bzero(&res, sizeof(ssize_t) * 2);
	ft_reverse(&champ->prog_size, PROG_LENGTH);
	champ->prog_size > CHAMP_MAX_SIZE ?
	ft_large(champ->prog_size, argv) : 0;
	champ->code = (t_char *)malloc(champ->prog_size);
	while ((res[0] = read(fd, champ->code, champ->prog_size)) > 0)
		res[1] += res[0];
	res[1] != champ->prog_size ? INV_PROG_SIZE(argv) : 0;
}

static	void	valid_data(t_play *champ, char *argv, ssize_t size)
{
	if (size < MIN_FILE_SIZE - PADDING * 2)
		SMALL_PROG(argv);
	ft_reverse(&champ->magic, MAGIC_LENGTH);
	champ->magic != COREWAR_EXEC_MAGIC ? INV_MAGIC(argv) : 0;
}

static void		read_data(int fd, t_play *champ, char *argv)
{
	ssize_t size;

	size = 0;
	size += read(fd, &champ->magic, MAGIC_LENGTH);
	size += read(fd, champ->prog_name, PROG_NAME);
	lseek(fd, PADDING, 1);
	size += read(fd, &champ->prog_size, PROG_LENGTH);
	size += read(fd, champ->comment, COMMENT_LENGTH);
	lseek(fd, PADDING, 1);
	valid_data(champ, argv, size);
	read_exec_code(fd, champ, argv);
}

static	void	fill_id(t_data *data)
{
	int j;
	int id;

	j = -1;
	id = -1;
	while (++j < MAX_PLAYERS)
	{
		data->champ[j].id = id;
		id += -1;
	}
}

void			parse_arguments(t_data *data, int argc, char **argv)
{
	int k;
	int fd;

	k = 0;
	!argc ? ft_usage() : 0;
	fill_id(data);
	parse_flags(data, argc, argv);
	while (k < argc)
	{
		k += check_arguments(data, &argv[k]);
		k == argc ? ft_usage() : 0;
		if ((fd = open(argv[k], O_RDONLY)) == -1)
			FAIL_OPEN(argv[k]);
		read_data(fd, &data->champ[data->quantity], argv[k]);
		close(fd);
		data->quantity++;
		k++;
	}
	data->num = 1;
	data->cycle_to_die = CYCLE_TO_DIE;
}
