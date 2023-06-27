/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:49:13 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/27 05:39:09 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sort(t_stake **pile)
{
	t_stake	*tmp;
	int		i;

	tmp = *pile;
	i = 0;
	while (tmp)
	{
		if (tmp->index != i)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int	index_to_moov(t_stake **pile, int bits_rank)
{
	t_stake	*tmp;
	int		i;

	tmp = *pile;
	i = 0;
	while (tmp)
	{
		if (!((tmp->index >> bits_rank) & 1))
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

void	sort_pile(t_stake **pile_a, t_stake **pile_b, int bit_max)
{
	int bit_rank;
	int to_move;
	t_stake *tmp;

	bit_rank = 0;
	to_move = 0;
	tmp = *pile_a;
	while (bit_rank < bit_max)
	{
		if (is_sort(pile_a) && ft_lstsize_ps(pile_b) == 0)
			return ;
		while (to_move > -1)
		{
			to_move = index_to_moov(pile_a, bit_rank);
			if (to_move == 0)
			{
				pb(pile_a, pile_b);
				to_move = index_to_moov(pile_a, bit_rank);
			}
			else if (to_move > ft_lstsize_ps(pile_a) / 2)
			{
				while (ft_lstsize_ps(pile_a) - to_move)
				{
					rra(pile_a);
					to_move = index_to_moov(pile_a, bit_rank);
				}
			}
			else if (to_move <= ft_lstsize_ps(pile_a) / 2 && to_move > -1)
			{
				while (to_move)
				{
					ra(pile_a);
					to_move = index_to_moov(pile_a, bit_rank);
				}
			}
		}
		bit_rank++;
		to_move = index_to_moov(pile_a, bit_rank);
		while (ft_lstsize_ps(pile_b))
		{
			pa(pile_b, pile_a);
		}
	}
}