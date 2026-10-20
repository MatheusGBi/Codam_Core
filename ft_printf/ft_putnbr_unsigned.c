/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putnbr_unsigned.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/19 17:18:08 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/19 17:18:10 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		ctr;

	ctr = 0;
	if (n > 9)
		ctr += ft_putnbr_unsigned((n / 10));
	c = (n % 10) + '0';
	ctr += write(1, &c, 1);
	return (ctr);
}
