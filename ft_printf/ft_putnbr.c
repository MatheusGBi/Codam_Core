/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_putnbr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/19 17:11:56 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/19 17:12:01 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	long	nb;
	int		ctr;

	nb = n;
	ctr = 0;
	if (nb < 0)
	{
		nb = -nb;
		ctr += write(1, "-", 1);
	}
	if (nb > 9)
		ctr += ft_putnbr((nb / 10));
	c = (nb % 10) + '0';
	ctr += write(1, &c, 1);
	return (ctr);
}
