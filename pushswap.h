/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:56:12 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/06 21:07:31 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				index;
	char			*d;
	struct s_list	*next;
}					t_list;
int		feedlstc(char **spl, t_list **a, int i);
int		checkrepeatc(t_list **ls);
void	forcefree(t_list	*clone);
char	**splitargvc(char	*argv[]);
int		ft_move(char *line, t_list **a, t_list **b);
char	*get_next_line(int fd);
void	quick_sort(t_list **a, int i);
void	checkarg(char **arg);
char	**splitargv(char *argv[]);
int		feedlst(char **spl, t_list **a, int i);
int		checknbr(char *str);
long	ft_atoi(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_join(char *s1, char *s2);
void	bitonicsort(t_list **stack_a, int i);
char	*decimal_to_binary(int decimal, int digits);
int		binarysize(int decimal);
void	lstbinary(t_list **a);
int		bubble_sort(t_list **head);
int		lstbinarysize(t_list **a);
t_list	*clonelst(char **argv);
void	indexin(t_list **a, t_list **c);
t_list	*ft_lstnew(int content, int s, char *bn);
void	pop_index(t_list	**head, int index);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	delete_first_node(t_list **head);
void	sa(t_list	**head, int x);
void	sb(t_list	**b, int x);
void	pb(t_list	**a,	t_list	**b, int x);
void	pa(t_list **stack_a, t_list **stack_b, int x);
void	ra(t_list	**a, int x);
void	rb(t_list	**b, int x);
void	ss(t_list	**b, t_list **a, int x);
void	rr(t_list	**a, t_list **b, int x);
void	rra(t_list	**a, int x);
void	rrb(t_list	**b, int x);
void	rrr(t_list	**a, t_list	**b, int x);
#endif