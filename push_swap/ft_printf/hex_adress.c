/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printhex.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/16 16:16:57 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/16 16:16:59 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	write_hex(unsigned char *hx)
{
	int	i;
	int	f;
	int	c;

	f = 0;
	i = 0;
	c = 0;
	while (i < 16)
	{
		if (f == 0 && hx[i] == '0')
			i++;
		else
		{
			write(1, &hx[i++], 1);
			f = 1;
			c++;
		}
	}
	return (c);
}

int	hex_adress(void *adress)
{
	char				*h;
	int					i;
	unsigned long long	p;
	unsigned char		hex[16];

	p = (unsigned long long)adress;
	i = 15;
	h = "0123456789abcdef";
	if (!adress)
		return (write(1, "(nil)", 5), 5);
	if (p == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	while (i >= 0)
	{
		hex[i--] = h[p % 16];
		p = p / 16;
	}
	i = 0;
	return ((write_hex(hex) + 2));
}
