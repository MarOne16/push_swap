/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SaSbPaPb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:23:53 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/28 12:59:03 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void sa(t_list **a)
{
    t_list *temp = (*a);
    (*a) = (*a)->next;
    temp->next = (*a)->next;
    (*a)->next = temp;
	write(1, "sa\n", 3);
}

void	sb(t_list** b)
{
	t_list	*sb;

	if (!(*b)->next)
	{
		return ;
	}
	sb = *b;
	*b = (*b)->next;
	sb->next = (*b)->next;
	(*b)->next = sb;
	write(1, "sb\n", 3);
}

void ss(t_list** b, t_list** a)
{
    t_list* sa;
    t_list* sb;

    if (!(*a)->next || !(*b)->next)
        return;

    sa = *a;
    *a = (*a)->next;
    sa->next = (*a)->next;
    (*a)->next = sa;
    sb = *b;
    *b = (*b)->next;
    sb->next = (*b)->next;
    (*b)->next = sb;
    write(1, "ss\n", 3);
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
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
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
	write(1, "ra\n", 3);
}
