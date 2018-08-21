/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_for_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:22:02 by ddryha            #+#    #+#             */
/*   Updated: 2018/08/10 13:22:03 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static	void	del_content(void *ptr, size_t size)
{
	ft_bzero(ptr, size);
	free(ptr);
	size = 0;
}

static	void	del_save_lst(t_data *data, t_list *del, t_list **pre)
{
	if ((*(t_proc *)del->content).live)
	{
		if (!*pre)
		{
			*pre = del;
			data->proc = *pre;
		}
		else
		{
			(*pre)->next = del;
			*pre = (*pre)->next;
		}
		(*pre)->next = NULL;
	}
	else
	{
		if (DEATHS)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				((t_proc *)(del->content))->num,
				((t_proc *)(del->content))->no_live,
				data->cycle_to_die);
		ft_lstdelone(&del, &del_content);
	}
}

void			ft_lstdelif(t_data *data)
{
	t_list *pre;
	t_list *del;
	t_list *next;

	del = data->proc;
	pre = NULL;
	while (del)
	{
		next = del->next;
		del_save_lst(data, del, &pre);
		del = next;
	}
	data->proc = !pre ? NULL : data->proc;
}

void			add_to_begin(t_list **head, t_list **new)
{
	t_list *temp;
	t_list *next;

	temp = (*new)->next;
	(*new)->next = NULL;
	while (temp)
	{
		next = temp->next;
		ft_lstadd(head, temp);
		temp = next;
	}
}

void			free_data(t_data *data)
{
	t_list	*temp;
	int		j;

	j = -1;
	while (++j < data->quantity)
		free(data->champ[j].code);
	if (DEATHS)
	{
		temp = data->proc;
		while (temp)
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				((t_proc *)(temp->content))->num,
				((t_proc *)(temp->content))->no_live,
				data->cycle_to_die);
			temp = temp->next;
		}
	}
	ft_lstdel(&data->proc, &del_content);
}
