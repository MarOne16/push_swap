/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:12 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/28 20:42:33 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

typedef struct s_list
{
	int				content;
	int				index;
	char			*d;
	struct s_list	*next;
}					t_list;

char**	splitargv(char* argv[]);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_join(char *s1, char *s2);
void	bitonicsort(t_list **stack_a, t_list **stack_b, int i);
char	*decimal_to_binary(int decimal, int digits);
int		binarysize(int decimal);
void	lstbinary(t_list **a);
void	bubble_sort(t_list **head);
int		lstbinarysize(t_list **a);
t_list	*clonelst(char **argv);
void	indexin(t_list **a, t_list **c);
int		lastindex(t_list **a, int i);
t_list	*ft_lstnew(int content ,int s , char *bn);
void	pop_index(t_list** head, int index);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	delete_first_node(t_list **head);
void	sa(t_list** head);
void	pb(t_list	**a,	t_list	**b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list** a);
void	rb(t_list** b);
void	ss(t_list** b, t_list **a);
void	rr(t_list** a, t_list **b);
void	rra(t_list** a);
void	rrb(t_list** b);
void	rrr(t_list **a, t_list** b);
#endif