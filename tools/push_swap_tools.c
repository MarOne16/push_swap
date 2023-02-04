/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:37:11 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/04 19:42:38 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	binarysize(int decimal)
{
	int	digits;

	digits = 0;
	while (decimal > 0)
	{
		decimal >>= 1;
		digits++;
	}
	return (digits);
}

char	*decimal_to_binary(int decimal, int digits)
{
	char	*binary;
	int		index;

	binary = malloc((digits + 1) * sizeof(char));
	if (!binary)
		return (0);
	index = digits - 1;
	while (index >= 0)
	{
		binary[index] = (decimal & 1) + '0';
		decimal >>= 1;
		index--;
	}
	binary[digits] = '\0';
	return (binary);
}

int	lstbinarysize(t_list **a)
{
	t_list	*rest;
	int		i;

	i = 0;
	rest = (*a);
	while ((*a))
	{
		if (binarysize((*a)->index) > i)
			i = binarysize((*a)->index);
		(*a) = (*a)->next;
	}
	(*a) = rest;
	return (i);
}

void	lstbinary(t_list **a)
{
	t_list	*rest_a;
	int		size;

	rest_a = (*a);
	size = lstbinarysize(a);
	while ((*a))
	{
		(*a)->d = decimal_to_binary((*a)->index, size);
		(*a) = (*a)->next;
	}
	*a = rest_a;
}

int	bubble_sort(t_list **head)
{
	t_list	*current;
	int		sorted;
	int		temp;
	int		s;

	sorted = 0;
	s = 0;
	while (!sorted)
	{
		sorted = 1;
		current = *head;
		while (current->next != NULL)
		{
			if (current->content > current->next->content)
			{
				temp = current->content;
				current->content = current->next->content;
				current->next->content = temp;
				sorted = 0;
				s = 1;
			}
			current = current->next;
		}
	}
	return (s);
}
