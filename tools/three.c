/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:24:17 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/29 19:07:10 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_list(t_list **a)
{
	t_list *temp;

	if (*a == NULL || (*a)->next == NULL)
		return;

	while (1)
	{
		temp = *a;
		while (temp->next != NULL)
		{
			if (temp->data > temp->next->data)
			{
				sa(a);
				break ;
			}
			temp = temp->next;
		}
		if (temp->next == NULL)
			break ;
	}
	while ((*a)->data > (*a)->next->data)
		ra(a);
	while ((*a)->next->data > (*a)->next->next->data)
		rra(a);
}
		while (*a)
		{
			printf("%d ",(*a)->content);
			(*a) = (*a)->next;
		}
		