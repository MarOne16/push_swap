/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:24:17 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/30 19:53:41 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_three(t_list **a)
{
	if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		sa(a ,1);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa(a ,1);
		rra(a ,1);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		ra(a ,1);
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
	{
		sa(a ,1);
		ra(a ,1);
	}
	else if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content
		&& (*a)->content > (*a)->next->next->content)
		rra(a ,1);
}

void	sort_foor(t_list **a)
{
	t_list	*b;

	b = NULL;
	while ((*a)->index != 1)
		ra(a ,1);
	pb(a, &b ,1);
	sort_three(a);
	pa(a, &b ,1);
}

void	sort_five(t_list **a)
{
	t_list	*b;

	b = NULL;
	if ((*a)->index == 1 && (*a)->next->index == 2)
	{
		pb(a, &b ,1);
		pb(a, &b ,1);
		sort_three(a);
		pa(a, &b ,1);
		pa(a, &b ,1);
		return ;
	}
	while ((*a)->index != 1)
		ra(a ,1);
	pb(a, &b ,1);
	while ((*a)->index != 2)
		ra(a ,1);
	pb(a, &b ,1);
	sort_three(a);
	pa(a, &b ,1);
	pa(a, &b ,1);
}

void	quick_sort(t_list **a, int i)
{
	if (i == 2)
	{
		sa(a ,1);
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
