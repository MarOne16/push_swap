/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:57:36 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/06 20:25:37 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rb(t_list **b, int x)
{
	t_list	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b);
	while ((tmp)->next)
		(tmp) = (tmp)->next;
	tmp->next = (*b);
	(*b) = (*b)->next;
	tmp->next->next = NULL;
	if (x == 1)
		write(1, "pa\n", 3);
}

void	rr(t_list **a, t_list **b, int x)
{
	ra(a, 0);
	rb(b, 0);
	if (x == 1)
		write(1, "rr\n", 3);
}

void	rra(t_list **a, int x)
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
	if (x == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int x)
{
	t_list	*temp;
	t_list	*prev;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	prev = NULL;
	temp = *b;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = *b;
	*b = temp;
	if (x == 1)
		write(1, "rrb\n", 4);
}

void	ra(t_list	**a, int x)
{
	t_list	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*a);
	(*a) = (*a)->next;
	tmp->next->next = NULL;
	if (x == 1)
		write(1, "ra\n", 3);
}
