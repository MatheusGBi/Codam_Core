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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	size = ft_strlen (s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (size > i && ft_strchr(set, s1[size - 1]))
		size--;
	return (ft_substr(s1, i, size - i));
}
