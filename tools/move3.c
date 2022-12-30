/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:06:46 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/30 20:58:50 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rrar(t_list **a)
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
}

void	rrbr(t_list **b)
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
}

void	rrr(t_list **a, t_list **b, int x)
{
	rrar(a);
	rrar(b);
	if (x == 0)
		write(1, "rrr\n", 4);
}