/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:57:36 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/29 22:43:16 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rb(t_list **b)
{
	t_list	*tmp;

	if (!(*b)->next)
		return ;
	tmp = (*b);
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	tmp->next = (*b);
	(*b) = (*b)->next;
	tmp->next->next = NULL;
}

void	rr(t_list **a, t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp;

	if (!((*b)->next || (*a)->next))
		return ;
	tmp1 = (*b);
	while ((tmp1)->next)
		(tmp1) = (tmp1)->next;
	tmp1->next = (*b);
	(*b) = (*b)->next;
	tmp1->next->next = NULL;
	tmp = (*a);
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	tmp->next = (*a);
	(*a) = (*a)->next;
	tmp->next->next = NULL;
}

void	rra(t_list **a)
{
	t_list	*temp;
	t_list	*prev;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	prev = NULL;
	temp = *a;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = *a;
	*a = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*last;
	t_list	*first;

	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	while (first->next->next)
	{
		first = first->next;
	}
	first->next = NULL;
	ft_lstadd_front(b, last);
}

void	ra(t_list	**a)
{
	t_list	*tmp;

	if (!(*a)->next)
		return ;
	tmp = (*a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*a);
	(*a) = (*a)->next;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}
