/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <bmoudach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:10:11 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/24 15:29:20 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"
#include"../libft/libft.h"

t_stake	*ft_lstnew_ps(int content)
{
	t_stake	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize_ps(t_stake **pile)
{
	t_stake *tmp;
	int	i;
	
	i = 0;
	tmp = *pile;
	while(tmp)
	{
		tmp=tmp->next;
		i++;
	}
	return (i);
}

t_stake	*ft_lstlast_ps(t_stake *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_stake **lst, t_stake *new)
{
	if (*lst)
		ft_lstlast_ps(*lst)->next = new;
	else
		*lst = new;
}

t_stake	*ft_atoi_ps(const char *str, int *error)
{
	int					i;
	int					signe;
	long long			base;

	base = 0;
	signe = 1;
	i = 0;
	*error = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		base = (base * 10) + str[i] - '0';
		i++;
		*error = 0;
	}
	base = base * signe;
	if (base > INT_MAX || base < INT_MIN || str[i])
		*error = 1;
	return (ft_lstnew_ps(base));
}
