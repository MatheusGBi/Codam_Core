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

char	*ft_strdup(const char *s)
{
	char		*res;
	size_t		i;
	size_t		size;

	size = ft_strlen(s);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = (char)s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
