/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojonker <mojonker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:18:47 by mgiraldi          #+#    #+#             */
/*   Updated: 2026/11/18 16:34:53 by mojonker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_ten(int **stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = -1;
	while (i < size)
	{
		if (stack[1][i] > max)
			max = stack[1][i];
		i++;
	}
	i = 1;
	while (max > i && max > 9)
	{
		i = i * 10;
	}
	return (i);
}

int	binary(int n)
{
	if (n == 0)
		return (0);
	else
		return ((n % 2) + (10 * binary(n / 2)));
}

void	converttobase(t_stack_sct *stackab, int	*temp)
{
	int	counter;

	counter = 0;
	while (counter < stackab->size_a)
	{
		temp[counter] = binary(temp[counter]);
		counter++;
	}
}

void	sort(t_stack_sct *stackab, t_bench_md *bench, int ten)
{
	int	i;
	int	size;

	size = stackab->size_a;
	i = 0;
	while (i < size)
	{
		if ((stackab->stack_a[1][0] / ten) % 10 != 1)
			pb(stackab, bench);
		else
			ra(stackab, bench);
		i++;
	}
	while (stackab->size_b > 0)
		pa(stackab, bench);
}

void	complex(t_stack_sct *stackab, t_bench_md *bench)
{
	int	ten;
	int	i;

	rank_indexing(stackab);
	converttobase(stackab, stackab->stack_a[1]);
	ten = biggest_ten(stackab->stack_a, stackab->size_a);
	i = 1;
	while (i < ten)
	{
		sort(stackab, bench, i);
		i = i * 10;
	}
	rank_indexing(stackab);
}
