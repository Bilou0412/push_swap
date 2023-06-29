/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 05:18:27 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/29 05:18:33 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sort(t_stake **pile)
{
	t_stake	*tmp;

	tmp = *pile;
	while (tmp->next)
	{
		if (tmp->index + 1 != tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_pile_b(int bit_rank, int bit_max, t_stake **pile_b,
		t_stake **pile_a)
{
	t_stake	*tmp;
	int		size;

	tmp = *pile_b;
	size = ft_lstsize_ps(pile_b);
	while (size)
	{
		tmp = *pile_b;
		if ((!((tmp->index >> bit_rank) & 1)) == 0)
		{
			pa(pile_b, pile_a);
			size--;
		}
		else if (bit_rank < bit_max)
		{
			rb(pile_b);
			size--;
		}
		else
			size--;
	}
}

void	sort_pile(t_stake **pile_a, t_stake **pile_b, int bit_max)
{
	int		bit_rank;
	t_stake	*tmp;
	int		size;

	bit_rank = 0;
	while (bit_rank < bit_max)
	{
		size = ft_lstsize_ps(pile_a);
		while (size--)
		{
			tmp = *pile_a;
			if (((tmp->index >> bit_rank) & 1) == 0 && !is_sort(pile_a))
			{
				pb(pile_a, pile_b);
			}
			else if (!is_sort(pile_a))
			{
				ra(pile_a);
			}
		}
		bit_rank++;
		sort_pile_b(bit_rank, bit_max, pile_b, pile_a);
	}
	while (ft_lstsize_ps(pile_b))
		pa(pile_b, pile_a);
}

void	sort_three(t_stake **pile_a)
{
	t_stake	*tmp;

	tmp = *pile_a;
	if (tmp->index > tmp->next->index
		&& tmp->next->next->index < tmp->next->index)
	{
		sa(pile_a);
		ra(pile_a);
		ra(pile_a);
	}
	while (!is_sort(pile_a))
	{
		tmp = *pile_a;
		if (tmp->index > tmp->next->index
			|| tmp->index > tmp->next->next->index)
			ra(pile_a);
		else if (tmp->index < tmp->next->index
			&& tmp->index < tmp->next->next->index
			&& tmp->next->index > tmp->next->next->index && !is_sort(pile_a))
		{
			sa(pile_a);
			while (!is_sort(pile_a))
				ra(pile_a);
		}
	}
}

void	sort_five(t_stake **pile_a, t_stake **pile_b)
{
	t_stake	*tmp_a;
	t_stake	*tmp_b;

	tmp_b = *pile_b;
	while (ft_lstsize_ps(pile_b) < 2)
	{
		tmp_a = *pile_a;
		if (tmp_a->index != 0 && tmp_a->index != 1)
			ra(pile_a);
		else
			pb(pile_a, pile_b);
	}
	sort_three(pile_a);
	while (is_sort(pile_b))
		rb(pile_b);
	while (ft_lstsize_ps(pile_b))
		pa(pile_b, pile_a);
}
