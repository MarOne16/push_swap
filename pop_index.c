/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:13:22 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/25 16:14:27 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void pop_index(t_list** head, int index)
{
	if (*head == NULL || index < 0)
		return;

	t_list* current = *head;
	t_list* previous = NULL;

	int i = 0;
	while (current != NULL && i < index)
	{
    previous = current;
    current = current->next;
    i++;
	}
	if (current == NULL)
		return;
	if (previous == NULL)
		*head = current->next;
	else
		previous->next = current->next;
	free(current);
}