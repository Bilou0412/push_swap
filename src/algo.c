/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:49:13 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/27 20:52:49 by bmoudach         ###   ########.fr       */
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

void	sort_pile(t_stake **pile_a, t_stake **pile_b, int bit_max)
{
	int bit_rank;
	t_stake *tmp;
	int	size;

	bit_rank = 0;
	while (bit_rank < bit_max)
	{
		size = ft_lstsize_ps(pile_a);
		while (size)
		{
			tmp = *pile_a;
			if (((tmp->index >> bit_rank) & 1) == 0)
			{
				pb(pile_a, pile_b);
				size--;
			}
			else
			{
				ra(pile_a);
				size--;
			}
		}
		while (ft_lstsize_ps(pile_b) > 0)
		{
			pa(pile_b, pile_a);
		}
		bit_rank++;
	}
}