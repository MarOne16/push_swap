/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:49:26 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/29 12:11:32 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_list	*clonelst(char **argv)
{
	int		i;
	t_list	*a;

	i = 0;
	a = NULL;
	while (argv[++i])
	{
		int	z;
		t_list	*ls;

		z = atoi(argv[i]);
		ls = ft_lstnew(z, i, 0);
		ft_lstadd_back(&a, ls);
	}
	bubble_sort(&a);
	return (a);
}

void	indexin(t_list **a, t_list **c)
{
	t_list	*rest;
	t_list	*rest_a;

	rest_a = (*a);
	while ((*a))
	{
		rest = (*c);
		while (rest)
		{
			if ((*a)->content == rest->content)
				(*a)->index = rest->index;
			rest = rest->next;
		}
		*a = (*a)->next;
	}
	*a = rest_a;
}

int	lastindex(t_list **a, int i)
{
	t_list	*ls;
	int		x;

	ls = *a;
	x = 0;
	while (ls->next)
	{
		if (ls->d[i] == ls->next->d[i])
			x += 1;
		else
			x = 0;
		ls = ls->next;
	}
	return (x);
}

void	bitonicsort(t_list **stack_a, t_list **stack_b, int i)
{
	int	x;
	int	b;
	int	min;
	int	z;

	x = 1;
	b = lstbinarysize(stack_a);
	while (b-- > 0)
	{
		min = lastindex(stack_a, b);
		x = i - 1;
		z = 0;
		while (--x >= 0)
		{
			if ((*stack_a)->d[b] == '1')
				ra(stack_a);
			else if ((*stack_a)->d[b] == '0')
			{
				pb(stack_a, stack_b);
				z++;
			}
		}
		while (z-- > 0)
			pa(stack_a, stack_b);
	}
}