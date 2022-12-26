/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:55:50 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/26 17:16:56 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstnew(int content , int s ,char *bn)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (0);
	node -> content = content;
	node->index=s;
	node->d = bn;
	node -> next = 0;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*l;

	if (!lst)
		return (0x0);
	l = lst;
	while (l -> next != 0)
	{
		l = l -> next;
	}
	return (l);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst2;

	if (lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new;
	}
	else
	{
		lst2 = ft_lstlast(*lst);
		lst2 -> next = new;
	}
}
