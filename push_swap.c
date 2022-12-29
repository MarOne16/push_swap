/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:59:14 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/29 18:42:13 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checknbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9' ) && (str[i] != '-' && str[i] != '+'))
		{
			write(2, "Error", 5);
			exit(2);
		}
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
		{
			write(2, "Error", 5);
			exit(2);
		}
		i++;
	}
	return (1);
}

void	forcfree(t_list	*clone)
{
	t_list	*help;

	while (clone)
	{
		help = clone;
		clone = clone->next;
		free(help);
	}
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
			{
				forcfree(*ls);
				write(2, "Error", 5);
				exit(2);
			}
			ls2 = ls2->next;
		}
		(*ls) = (*ls)->next;
	}
	(*ls) = rest;
	return (0);
}

char	**splitargv(char	*argv[])
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
	free(spl);
	return (tmp);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**spl;
	t_list	*a;
	t_list	*clone;

	if (argc < 2)
		return (0);
	i = -1;
	a = NULL;
	spl = splitargv(argv);
	i = feedlst(spl, &a, i);
	checkrepeat(&a);
	clone = clonelst(argv);
	three(&a,i);
	indexin(&a, &clone);
	forcfree(clone);
	lstbinary(&a);
	bitonicsort(&a, i + 1);
}
