/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_normalise.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:25:01 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/30 14:34:32 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_bit(int nb)
{
	int	i;

	i = 0;
	while (nb >= 2)
	{
		nb = nb / 2;
		i++;
	}
	i++;
	return (i);
}

void	init_index(t_stake **pile)
{
	t_stake	*tmp;
	int		i;

	i = 0;
	tmp = *pile;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = *pile;
	while (tmp->next)
	{
		tmp->index = i;
		tmp = tmp->next;
	}
	tmp->index = i;
}

void	normalise(t_stake **pile)
{
	t_stake	*tmp;
	t_stake	*tmp_buf;

	init_index(pile);
	tmp = *pile;
	tmp_buf = *pile;
	while (tmp)
	{
		while (tmp_buf)
		{
			if (tmp->data < tmp_buf->data)
				tmp->index = tmp->index - 1;
			tmp_buf = tmp_buf->next;
		}
		tmp_buf = *pile;
		tmp = tmp->next;
	}
}

void	ft_lstdelone_ps(t_stake *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear_ps(t_stake **lst)
{
	t_stake	*t;
	t_stake	*buf;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		buf = t->next;
		ft_lstdelone_ps(t);
		t = buf;
	}
	*lst = NULL;
}
