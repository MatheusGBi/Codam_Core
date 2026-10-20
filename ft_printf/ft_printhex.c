/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printhex.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/19 15:38:27 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/19 15:38:29 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printhex(unsigned int f, char *base)
{
	int		i;
	char	temp;

	i = 0;
	if (f > 15)
		i += ft_printhex(f / 16, base);
	temp = base[f % 16];
	i += write (1, &temp, 1);
	return (i);
}
