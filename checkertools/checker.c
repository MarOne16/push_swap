/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:18:42 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/05 15:34:49 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_move(char *line, t_list	**a, t_list	**b)
{
	if (strcmp(line, "sa\n") == 0)
		sa(a, 0);
	else if (strcmp(line, "sb\n") == 0)
		sb(b, 0);
	else if (strcmp(line, "ss\n") == 0)
		ss(b, a, 0);
	else if (strcmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else if (strcmp(line, "pb\n") == 0)
		pb(a, b, 0);
	else if (strcmp(line, "ra\n") == 0)
		ra(a, 0);
	else if (strcmp(line, "rb\n") == 0)
		rb(b, 0);
	else if (strcmp(line, "rr\n") == 0)
		rr(a, b, 0);
	else if (strcmp(line, "rra\n") == 0)
		rra(a, 0);
	else if (strcmp(line, "rrb\n") == 0)
		rrb(b, 0);
	else if (strcmp(line, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

int	sorting(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_move(line, a, b) == 1)
		{
			write(1, "Error", 5);
			exit(2);
		}
		line = get_next_line(0);
	}
	if ((bubble_sort(a) == 1) || (*b != NULL))
	{
		write(1, "KO", 2);
		exit(1);
	}
	else
	{
		write(1, "OK", 2);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**spl;
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	i = -1;
	a = NULL;
	b = NULL;
	spl = splitargvc(argv);
	i = feedlstc(spl, &a, i);
	checkrepeatc(&a);
	sorting(&a, &b);
	return (0);
}
