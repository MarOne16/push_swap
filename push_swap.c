/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:59:14 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/28 22:03:14 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int checknbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9' ) && (str[i] != '-' && str[i] != '+'))
			exit(1);
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-' || str[i + 1] == '+'))
			exit(1);
		i++;
	}
	return (1);
}

int	checkrepeat(t_list **ls)
{
	t_list	*ls2;
	t_list	*rest;

	rest = (*ls);
	while ((*ls)->next)
	{
		ls2 = (*ls)->next;
		while (ls2)
		{
			if ((*ls)->content == ls2->content)
				return (1);
			ls2 = ls2->next;
		}
		(*ls) = (*ls)->next;
	}
	(*ls) = rest;
	return (0);
}

void forcfree(t_list	*clone)
{
	t_list	*help;

	while(clone)
	{
		help = clone;
		clone = clone->next;
		free(help);
	}
	
}

char** splitargv(char* argv[])
{
	char	*spl;
	int		i;
	char	**tmp;

	i = 1;
	spl = NULL;
    while (argv[i])
    {
        spl = ft_join(spl, argv[i]);
        spl = ft_join(spl, " ");
        i++;
    }
    tmp = ft_split(spl, ' ');
    return (tmp);
}

int main(int argc, char *argv[])
{
	int		i;
	// int		x = 0;
	char	**spl;
	t_list	*a;
	t_list	*b;
	t_list	*clone;
	// t_list *ls;
	i = -1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	spl = splitargv(argv);
	while (spl[++i])
	{
		// checknbr(spl[i]);
		int	n = atoi(spl[i]);
		ft_lstadd_back(&a, ft_lstnew(n, i , 0));
	}
	// checkrepeat(&a); TODO if true break
	// printf("[%d]\n",i);
	clone = clonelst(argv);
	indexin(&a,&clone);
	lstbinary(&a);
	bitonicsort(&a , &b , i + 1);
	// forcfree(clone);
}