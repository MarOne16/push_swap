/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:12 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/26 17:16:28 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include<stdio.h>
#include<stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	char			*d;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(int content ,int s , char *bn);
void	pop_index(t_list** head, int index);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	delete_first_node(t_list **head);
void	sa(t_list** head);
void	pb(t_list	**a,	t_list	**b);
void	ra(t_list** a);
void	rb(t_list** b);
void	ss(t_list** b, t_list **a);
void	rr(t_list** a, t_list **b);
void	rra(t_list** a);
void	rrb(t_list** b);
void	rrr(t_list **a, t_list** b);
#endif