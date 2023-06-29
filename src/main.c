/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:04:53 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/29 03:17:21 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_double(t_stake **pile_a);

int	check_argument(char **arg, t_stake **pile_a)
{
	int		j;
	int		error;
	t_stake	*tmp;

	error = 0;
	j = 1;
	while (arg[j])
	{
		if (*pile_a == NULL)
			*pile_a = ft_atoi_ps(arg[j], &error);
		else
		{
			tmp = *pile_a;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ft_atoi_ps(arg[j], &error);
		}
		if (error)
			return (write(2, "Error\n", 6), 0);
		j++;
	}
	return (check_double(pile_a));
}

int	check_double(t_stake **pile_a)
{
	t_stake	*tmp_one;
	t_stake	*tmp_two;

	tmp_one = *pile_a;
	while (tmp_one)
	{
		tmp_two = tmp_one->next;
		while (tmp_two)
		{
			if (tmp_one->data == tmp_two->data)
				return (write(2, "Error\n", 6), 0);
			tmp_two = tmp_two->next;
		}
		tmp_one = tmp_one->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stake	*pile_a;
	t_stake	*pile_b;
	int		max_bits;

	pile_b = NULL;
	pile_a = NULL;
	if (argc < 2)
		return (0);
	if (argc >= 2)
	{
		if (!check_argument(argv, &pile_a))
			return (0);
	}
	normalise(&pile_a);
	if (is_sort(&pile_a))
		return (0);
	max_bits = max_bit(argc - 2);
	if (argc < 5)
		sort_three(&pile_a);
	else if (argc < 7)
		sort_five(&pile_a, &pile_b);
	else
		sort_pile(&pile_a, &pile_b, max_bits);
}
