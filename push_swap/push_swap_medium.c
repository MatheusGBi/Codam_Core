/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_medium.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/09 13:11:21 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/09 13:18:39 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_max_value_b(t_stack_sct *stackab)
{
	int	i;
	int	max_val;

	if (stackab->size_b <= 0)
		return (-1);
	max_val = stackab->stack_b[1][0];
	i = 1;
	while (i < stackab->size_b)
	{
		if (stackab->stack_b[1][i] > max_val)
			max_val = stackab->stack_b[1][i];
		i++;
	}
	return (max_val);
}

int	get_max_pos(t_stack_sct *stackab)
{
	int	i;
	int	j;

	if (stackab->size_b <= 0)
		return (0);
	j = 0;
	i = get_max_value_b(stackab);
	while (stackab->stack_b[1][j] != i)
		j++;
	return (j);
}

void	chunking(t_stack_sct *stackab, t_bench_md *bench, int chunk)
{
	int	start;
	int	rotated;

	start = 0;
	while (stackab->size_a > 0)
	{
		rotated = 0;
		while (rotated < chunk && stackab->size_a > 0)
		{
			if (stackab->stack_a[1][0] >= start
				&& stackab->stack_a[1][0] < start + chunk)
			{
				pb(stackab, bench);
				rotated++;
			}
			else if (check_shortest_path(stackab, start, start + chunk) == 1)
				ra(stackab, bench);
			else
				rra(stackab, bench);
		}
		start += chunk;
	}
}

void	chunk_push_back(t_stack_sct *stackab, t_bench_md *bench)
{
	int	moves;
	int	max;
	int	i;

	moves = 0;
	while (stackab->size_b > 0)
	{
		max = get_max_value_b(stackab);
		i = get_max_pos(stackab);
		while (stackab->stack_b[1][0] != max)
			if (i <= stackab->size_b / 2)
				rb(stackab, bench);
			else
				rrb(stackab, bench);
		pa(stackab, bench);
	}
}

void	chunk_sort(t_stack_sct *stackab, t_bench_md *bench)
{
	int	chunk;

	rank_indexing(stackab);
	chunk = 1.6 * ft_sqrt(stackab->size_a);
	chunking(stackab, bench, chunk);
	chunk_push_back(stackab, bench);
}
