/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:20:45 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/27 02:43:45 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stake **pile)
{
	t_stake	*tmp_one;
	t_stake	*tmp_two;

	tmp_one = *pile;
	if (!tmp_one->next)
		return ;
	tmp_two = tmp_one->next;
	tmp_one->next = tmp_two->next;
	tmp_two->next = *pile;
	*pile = tmp_two;
}

void	push(t_stake **pile_from, t_stake **pile_to)
{
	t_stake	*tmp_from_one;
	t_stake	*tmp_from_two;
	t_stake	*tmp_to_one;

	if (!*pile_from)
		return ;
	tmp_from_one = *pile_from;
	tmp_from_two = tmp_from_one->next;
	tmp_to_one = *pile_to;
	tmp_from_one->next = tmp_to_one;
	*pile_from = tmp_from_two;
	*pile_to = tmp_from_one;
}

void	rotate(t_stake **pile)
{
	t_stake	*tmp;
	t_stake	*tmp_last;
	t_stake	*tmp_two;

	tmp = *pile;
	if (!tmp->next)
		return ;
	tmp_two = tmp->next;
	tmp_last = ft_lstlast_ps(*pile);
	tmp->next = NULL;
	tmp_last->next = tmp;
	*pile = tmp_two;
}

void	reverse_rotate(t_stake **pile)
{
	t_stake	*tmp;
	t_stake	*tmp_last;
	t_stake	*tmp_prelast;
	t_stake	*buf;
	int		size;

	size = 0;
	tmp = *pile;
	if (!tmp->next)
		return ;
	buf = *pile;
	tmp_prelast = *pile;
	tmp_last = ft_lstlast_ps(*pile);
	while (buf->next)
	{
		buf = buf->next;
		size++;
	}
	while (size > 1)
	{
		tmp_prelast = tmp_prelast->next;
		size--;
	}
	*pile = tmp_last;
	tmp_last->next = tmp;
	tmp_prelast->next = NULL;
}
