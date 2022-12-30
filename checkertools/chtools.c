/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chtools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:36:49 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/30 21:02:31 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	checknbrc(char *str)
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

void	forcefree(t_list	*clone)
{
	t_list	*help;

	while (clone)
	{
		help = clone;
		clone = clone->next;
		free(help);
	}
}

int	checkrepeatc(t_list **ls)
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
				forcefree(*ls);
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

int	feedlstc(char **spl, t_list **a, int i)
{
	while (spl[++i])
	{
		checknbrc(spl[i]);
		if ((ft_atoi(spl[i]) > 2147483647) || (ft_atoi(spl[i]) < -2147483648))
		{
			write(2, "Error", 5);
			exit(2);
		}
		ft_lstadd_back(a, ft_lstnew(atoi(spl[i]), i, 0));
	}
	return (i);
}

char	**splitargvc(char	*argv[])
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
