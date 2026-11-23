/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_validity_check.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/03 18:14:03 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/03 18:14:08 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

int	dup_single_check(char **stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
		i++;
	if (i < 1)
		return (0);
	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while (stack[j])
		{
			if (ft_strcmp(stack[i], stack[j]) == 0)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	check_nbr(char *stack)
{
	int		i;
	int		neg;
	long	n;

	i = 0;
	n = 0;
	neg = 1;
	if (stack[i] == '-' || stack[i] == '+')
	{
		if (stack[i] == '-')
			neg = -1;
		i++;
	}
	if (!stack[i])
		return (0);
	while (stack[i])
	{
		n = n * 10 + (stack[i] - '0');
		if ((neg == 1 && n > 2147483647)
			|| (neg == -1 && (-n) < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	max_mincheck(char **stack)
{
	int		i;

	i = 0;
	while (stack[i])
	{
		if (!check_nbr(stack[i]))
			return (0);
		i++;
	}
	return (1);
}

int	stack_validity(char **stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = 0;
		if (stack[i][j] == '-')
			j++;
		if (!stack[i][j])
			return (0);
		while (stack[i][j])
		{
			if (stack[i][j] < '0' || stack[i][j] > '9')
				return (0);
			else
				j++;
		}
		i++;
		j = 0;
	}
	return (dup_single_check(stack) && max_mincheck(stack));
}
