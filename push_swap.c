/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:59:14 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/20 14:48:02 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	checkarg(char **arg)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	x = 0;
	while (arg[i])
	{
		j = -1;
		while (arg[i][++j])
		{
			if (arg[i][j] >= '0' && arg[i][j] <= '9')
				x = 1;
			if ((arg[i][j] >= '0' && arg[i][j] <= '9') &&
			(arg[i][j + 1] == '-' || arg[i][j + 1] == '+') &&
			(arg[i][j + 2] >= '0' && arg[i][j + 2] <= '9'))
				errr();
		}
		if (x == 0)
			errr();
		i++;
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
				exit(0);
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
	checkarg(argv);
	spl = splitargv(argv);
	i = feedlst(spl, &a, i);
	checkrepeat(&a);
	clone = clonelst(spl);
	indexin(&a, &clone);
	quick_sort(&a, i);
	newalgo(&a, i);
	forcfree(clone);
}

	// lstbinary(&a);
	// bitonicsort(&a, i + 1);