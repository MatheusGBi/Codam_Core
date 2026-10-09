/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_isalpha.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/09/29 14:21:22 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/09/29 14:21:25 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**free_all(char **str, size_t p)
{
	size_t	i;

	i = 0;
	while (p > i)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

size_t	split_count(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && (i == 0 || s[i - 1] == c)))
			j++;
		i++;
	}
	return (j);
}

size_t	str_size(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			i++;
		}
		else
			return (j);
	}
	return (j);
}

char	**string(char **str, char const *s, char c)
{
	size_t	ctr[4];

	ft_bzero(ctr, sizeof(ctr));
	while (s[ctr[0]])
	{
		if (s[ctr[0]] != c)
		{
			ctr[3] = str_size((s + ctr[0]), c);
			str[ctr[1]] = malloc(sizeof(char) * (ctr[3] + 1));
			if (!str[ctr[1]])
				return (free_all(str, ctr[1]));
			while (ctr[2] < ctr[3])
			{
				str[ctr[1]][ctr[2]++] = s[ctr[0]++];
			}
			str[ctr[1]++][ctr[2]] = '\0';
			ctr[2] = 0;
		}
		else
			(ctr[0])++;
	}
	str[ctr[1]] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	j;

	j = split_count(s, c);
	str = malloc(sizeof(char *) * (j + 1));
	if (!str)
		return (NULL);
	str = string(str, s, c);
	return (str);
}
