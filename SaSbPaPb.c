/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SaSbPaPb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:23:53 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/27 16:36:12 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void sa(t_list **a)
{
    t_list *temp = (*a);
    (*a) = (*a)->next;
    temp->next = (*a)->next;
    (*a)->next = temp;
}

void	sb(t_list** b)
{
	t_list	*sb;

	if (!(*b)->next)
	{
		// write(1, "sb\n", 3);
		return ;
	}
	sb = *b;
	*b = (*b)->next;
	sb->next = (*b)->next;
	(*b)->next = sb;
}
void	ss(t_list** b, t_list **a)//TODO edit 
{
	t_list	*sa;
	t_list	*sb;

	if (!(*a)->next)
	{
		// write(1, "sa\n", 3);
		return ;
	}
	sa = *a;
	*a = (*a)->next;
	sa->next = (*a)->next;
	(*a)->next = sa;
	
	if (!(*b)->next)
	{
		// write(1, "sb\n", 3);
		return ;
	}
	sb = *b;
	*b = (*b)->next;
	sb->next = (*b)->next;
	(*b)->next = sb;
	// write(1, "sb\n", 3);
}

void	pb(t_list	**stack_a,	t_list	**stack_b)
{
    if (*stack_a == NULL)
        return ;

    t_list  *top_a;
    top_a = *stack_a;
    *stack_a = (*stack_a)->next;
    top_a->next = *stack_b;
    *stack_b = top_a;
	printf("pb\n");
}

void pa(t_list **stack_a, t_list **stack_b)
{
    if (*stack_b == NULL)
        return ;

    t_list  *top_b;
    top_b = *stack_b;
    *stack_b = (*stack_b)->next;
    top_b->next = *stack_a;
    *stack_a = top_b;
	printf("pa\n");
}

void	ra(t_list** a)
{
	if (!(*a)->next)
		return;
	t_list	*tmp;

	tmp = (*a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*a);
	(*a) = (*a)->next;
	tmp->next->next = NULL;
	printf("ra\n");
}

void	rb(t_list** b)
{
	t_list	*tmp;

	if (!(*b)->next)
		return;
	tmp = (*b);
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	tmp->next = (*b);
	(*b) = (*b)->next;
	tmp->next->next = NULL;
	
}

void	rr(t_list** a, t_list **b)
{
	t_list	*tmp1;
	t_list	*tmp;

	if (!((*b)->next || (*a)->next))
		return;
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

void	rra(t_list** a)
{
	t_list	*last;
	t_list	*first;

	if (!(*a)->next)
		return;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	while (first->next->next)
	{
		first=first->next;
	}
	first->next=NULL;
	ft_lstadd_front(a,last);
}

void	rrb(t_list** b)
{
	t_list	*last;
	t_list	*first;

	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	while (first->next->next)
	{
		first=first->next;
	}
	first->next=NULL;
	ft_lstadd_front(b,last);
}
