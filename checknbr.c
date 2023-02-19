/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:59:16 by mqaos             #+#    #+#             */
/*   Updated: 2023/02/17 20:21:24 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	errr(void)
{
	write(2, "Error", 5);
	exit(0);
}

int	checknbr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9' ) && (str[i] != '-' && str[i] != '+'))
			errr();
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
			errr();
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			errr();
		if (i > 11)
			errr();
	}
	return (1);
}
