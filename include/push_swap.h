/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:39:36 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/29 05:17:02 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stake
{
	struct s_stake	*next;
	int				data;
	int				index;
	int				size;
	int				max_bin;
}					t_stake;

t_stake				*ft_lstnew_ps(int content);
void				display(t_stake **pile_a, t_stake **pile_b);
t_stake				*ft_lstlast_ps(t_stake *lst);
int					ft_lstsize_ps(t_stake **pile);
t_stake				*ft_atoi_ps(const char *str, int *error);
void				sort_pile(t_stake **pile_a, t_stake **pile_b, int bits_max);
void				swap(t_stake **pile);
void				push(t_stake **pile_from, t_stake **pile_to);
void				rotate(t_stake **pile);
void				reverse_rotate(t_stake **pile);
void				ft_lstadd_back_ps(t_stake **lst, t_stake *new);
void				sa(t_stake **pile_a);
void				sb(t_stake **pile_b);
void				pa(t_stake **pile_b, t_stake **pile_a);
void				pb(t_stake **pile_a, t_stake **pile_b);
void				ra(t_stake **pile_a);
void				rb(t_stake **pile_b);
void				rra(t_stake **pile_a);
void				rrb(t_stake **pile_b);
void				normalise(t_stake **pile);
int					max_bit(int nb);
int					is_sort(t_stake **pile);
void				sort_three(t_stake **pile_a);
void				sort_five(t_stake **pile_a, t_stake **pile_b);

#endif
