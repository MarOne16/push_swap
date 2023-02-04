/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:49:26 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/04 19:45:16 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_list	*clonelst(char **argv)
{
	int		i;
	t_list	*a;
	t_list	*ls;
	int		z;

	i = -1;
	a = NULL;
	while (argv[++i])
	{
		z = atoi(argv[i]);
		ls = ft_lstnew(z, i, 0);
		ft_lstadd_back(&a, ls);
	}
	if (!bubble_sort(&a))
		exit(1);
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

int	feedlst(char **spl, t_list **a, int i)
{
	while (spl[++i])
	{
		checknbr(spl[i]);
		if ((ft_atoi(spl[i]) > 2147483647) || (ft_atoi(spl[i]) < -2147483648))
		{
			write(2, "Error", 5);
			exit(2);
		}
		ft_lstadd_back(a, ft_lstnew(atoi(spl[i]), i, 0));
	}
	return (i);
}

void	bitonicsort(t_list **stack_a, int i)
{
	int		x;
	int		b;
	int		z;
	t_list	*stack_b;

	x = 1;
	stack_b = NULL;
	b = lstbinarysize(stack_a);
	while (b-- > 0)
	{
		x = i - 1;
		z = 0;
		while (--x >= 0)
		{
			if ((*stack_a)->d[b] == '1')
				ra(stack_a, 1);
			else if ((*stack_a)->d[b] == '0')
			{
				pb(stack_a, &stack_b, 1);
				z++;
			}
		}
		while (z-- > 0)
			pa(stack_a, &stack_b, 1);
	}
}
