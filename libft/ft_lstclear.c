/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoudach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:35:16 by bmoudach          #+#    #+#             */
/*   Updated: 2023/06/16 16:42:39 by bmoudach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	t_list	*buf;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		buf = t->next;
		ft_lstdelone(t, del);
		t = buf;
	}
	*lst = NULL;
}
