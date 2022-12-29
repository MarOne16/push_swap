/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:24:17 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/29 22:42:37 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_three(t_list **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		sa(a);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa(a);
		rra(a);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		ra(a);
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content
		&& (*a)->content > (*a)->next->next->content)
		rra(a);
}

void	sort_foor(t_list **a)
{
	t_list	*b;

	b = NULL;
	while ((*a)->index != 1)
		ra(a);
	pb(a, &b);
	sort_three(a);
	pa(a, &b);
}

void	sort_five(t_list **a)
{
	t_list	*b;

	b = NULL;
	if ((*a)->index == 1 && (*a)->next->index == 2)
	{
		pb(a, &b);
		pb(a, &b);
		sort_three(a);
		pa(a, &b);
		pa(a, &b);
		return ;
	}
	while ((*a)->index != 1)
		ra(a);
	pb(a, &b);
	while ((*a)->index != 2)
		ra(a);
	pb(a, &b);
	sort_three(a);
	pa(a, &b);
	pa(a, &b);
}

void	quick_sort(t_list **a, int i)
{
	if (i == 2)
	{
		sa(a);
		exit(1);
	}
	if (i == 3)
	{
		sort_three(a);
		exit(1);
	}
	if (i == 5)
	{
		sort_five(a);
		exit(1);
	}
	if (i == 4)
	{
		sort_foor(a);
		exit(1);
	}
	return ;
}
