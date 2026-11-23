/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_simple.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/05 13:55:37 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/05 13:55:38 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	selection_sort(t_stack_sct *stackab, t_bench_md *bench)
{
	int	min_index;

	rank_indexing(stackab);
	while (stackab->size_a > 0)
	{
		min_index = check_smallest(stackab);
		while (min_index != 0)
		{
			if (min_index <= stackab->size_a / 2)
				ra(stackab, bench);
			else
				rra(stackab, bench);
			min_index = check_smallest(stackab);
		}
		pb(stackab, bench);
	}
	while (stackab->size_b > 0)
		pa(stackab, bench);
}
