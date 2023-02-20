/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newalgo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:36:29 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/20 14:42:52 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	sort(t_list **a, t_list **b, int size3, int lenmax)
{
	while (b && (*b)->index != size3 - 1)
	{
		if (lenmax < (size3 / 2))
			rb(b, 1);
		else
			rrb(b, 1);
	}
	pa(a, b, 1);
}


int	countmove(t_list *r, int size3)
{
	int		lenmax;
	t_list	*reset;

	lenmax = 0;
	reset = r;
	while (r && r->index != size3 - 1)
	{
		lenmax++;
		r = r->next;
	}
	r = reset;
	return (lenmax);
}

void	pushtostackb(t_list **a, t_list **b, int x, int size2)
{
	int	i;
	int	max;

	i = 0;
	while (x--)
	{
		max = i;
		i += size2;
		while ((max != i))
		{
			if ((*a)->index <= i && max++)
			{
				if ((*a)->index > (i - (size2 / 2)))
				{
					pb(a, b, 1);
					rb(b, 1);
				}
				else
					pb(a, b, 1);
			}
			else
				ra(a, 1);
		}
	}
}

void	pushtoa(t_list	**a, t_list **b, int size3)
{
	int		lenmax;
	int		slenmax;
	t_list	*r;

	while ((*b) && size3)
	{
		r = (*b);
		lenmax = countmove(r, size3);
		slenmax = countmove(r, size3 - 1);
		if (abs(slenmax - (size3 / 2)) > abs(lenmax - (size3 / 2))
			&& (*b)->next)
		{
			sort(a, b, size3 - 1, slenmax);
			sort(a, b, size3, lenmax);
			sa(a, 1);
			size3--;
		}
		else
			sort(a, b, size3, lenmax);
		size3--;
	}
}

void	newalgo(t_list **a, int size)
{
	t_list	*b;
	int		size2;
	int		size3;
	int		x;

	size3 = size;
	b = NULL;
	x = 0;
	if (size >= 500)
	{
		size2 = size / 8; 
		x = 8;
	}
	else
	{
		size2 = size / 4;
		x = 4;
	}
	pushtostackb(a, &b, x, size2);
	while (*a && a)
		pb(a, &b, 1);
	pushtoa(a, &b, size3);
}
