/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_printf.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/15 17:37:11 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/15 17:37:13 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printfcheck(va_list list, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar((char)va_arg(list, int));
	else if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'p')
		count += hex_adress(va_arg(list, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(list, unsigned int));
	else if (c == 'x')
		count += ft_printhex(va_arg(list, int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_printhex(va_arg(list, int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	size_t	i;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	i = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			count += printfcheck(list, format[i]);
		}
		else
			count += write (1, &format[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}
