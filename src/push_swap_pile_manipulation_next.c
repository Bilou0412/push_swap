/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pile_manipulation_next.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:57:01 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/21 20:20:36 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rb(t_stake **pile_b)
{
	rotate(pile_b);
	write(1, "rb\n", 3);
}

void	rra(t_stake **pile_a)
{
	reverse_rotate(pile_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stake **pile_b)
{
	reverse_rotate(pile_b);
	write(1, "rrb\n", 4);
}
