/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:47:40 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/22 19:52:20 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

static void	rra2(t_list** a)
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

static void	rrb2(t_list** b)
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
void	rrr(t_list **a, t_list** b)
{
	rra2(a);
    rrb2(b);
}