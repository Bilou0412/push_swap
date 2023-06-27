/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pile_manipulation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:04:01 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/21 18:53:50 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stake **pile_a)
{
	swap(pile_a);
	write(1, "sa\n", 3);
}

void	sb(t_stake **pile_b)
{
	swap(pile_b);
	write(1, "sb\n", 3);
}

void	pa(t_stake **pile_b, t_stake **pile_a)
{
	push(pile_b, pile_a);
	write(1, "pa\n", 3);
}

void	pb(t_stake **pile_a, t_stake **pile_b)
{
	push(pile_a, pile_b);
	write(1, "pb\n", 3);
}

void	ra(t_stake **pile_a)
{
	rotate(pile_a);
	write(1, "ra\n", 3);
}
