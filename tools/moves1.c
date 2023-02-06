/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:23:53 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/06 20:21:10 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(t_list **a, int x)
{
	t_list	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = (*a);
	(*a) = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (x == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list	**b, int x)
{
	t_list	*sb;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	sb = *b;
	*b = (*b)->next;
	sb->next = (*b)->next;
	(*b)->next = sb;
	if (x == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list	**b, t_list	**a, int x)
{
	sa(a, 0);
	sb(b, 0);
	if (x == 1)
		write(1, "ss\n", 3);
}

void	pb(t_list	**stack_a,	t_list	**stack_b, int x)
{
	t_list	*top_a;

	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
	if (x == 1)
		write(1, "pb\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int x)
{
	t_list	*top_b;

	if (*stack_b == NULL)
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
	if (x == 1)
		write(1, "pa\n", 3);
}
