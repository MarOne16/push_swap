#include "pushswap.h"

static int	nb_c(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (nb);
}

static int	strlenword(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **strs, int j)
{
	while (j--)
		free(strs[j]);
	free(strs);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (0x0);
	i = 0;
	j = -1;
	str = (char **)malloc((nb_c(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < nb_c(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, strlenword(s, c, i));
		if (!str[j])
		{
			ft_free(str, j + 1);
			return (0);
		}
		i += strlenword(s, c, i);
	}
	str[j] = 0;
	return (str);
}