/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/20 18:23:05 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/20 18:23:07 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	str_len(char *l)
{
	int	i;

	if (!l)
		return (0);
	i = 0;
	while (l[i])
		i++;
	return (i);
}

char	*str_append(char *src, char *dest)
{
	int		i;
	int		j;
	char	*rtn;

	rtn = malloc((str_len(src) + str_len(dest) + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (src[i])
	{
		rtn[i] = src[i];
		i++;
	}
	j = 0;
	while (dest[j])
	{
		rtn[i + j] = dest[j];
		j++;
	}
	rtn[i + j] = '\0';
	return (rtn);
}

char	*buff_append(char *src, char *dest)
{
	char	*rtn;

	if (!dest)
		return (NULL);
	if (!src)
	{
		src = malloc(1);
		if (!src)
			return (NULL);
		src[0] = '\0';
	}
	rtn = str_append(src, dest);
	free(src);
	return (rtn);
}

int	str_char(char *src, char c)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}
