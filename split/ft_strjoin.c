/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqaos <mqaos@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:13:17 by mqaos             #+#    #+#             */
/*   Updated: 2022/12/29 18:17:01 by mqaos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pushswap.h"

size_t	ft_strlenn(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		u;
	char	*s3;

	i = -1;
	u = -1;
	s3 = malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!s3)
		return (0);
	while (s1 && s1[++i])
		s3[++u] = s1[i];
	i = -1;
	while (s2[++i] && s2)
		s3[++u] = s2[i];
	s3[++u] = '\0';
	free(s1);
	return (s3);
}
