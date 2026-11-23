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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	if (size == 0 || size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = 0;
	j = ft_strlen(dst);
	dst_len = j;
	while (src[i] && j < (size - 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ft_strlen(src) + dst_len);
}
