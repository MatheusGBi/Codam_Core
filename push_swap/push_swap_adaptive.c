/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_adaptive.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/16 13:33:34 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/16 13:33:35 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_stack_sct *stackab, t_bench_md *bench)
{
	if (stackab->stack_a[1][0] > stackab->stack_a[1][1] &&
		stackab->stack_a[1][1] < stackab->stack_a[1][2] &&
		stackab->stack_a[1][0] < stackab->stack_a[1][2])
		sa(stackab, bench);
	else if (stackab->stack_a[1][0] > stackab->stack_a[1][1]
		&& stackab->stack_a[1][1] > stackab->stack_a[1][2])
	{
		sa(stackab, bench);
		rra(stackab, bench);
	}
	else if (stackab->stack_a[1][0] > stackab->stack_a[1][1] &&
		stackab->stack_a[1][1] < stackab->stack_a[1][2] &&
		stackab->stack_a[1][0] > stackab->stack_a[1][2])
		ra(stackab, bench);
	else if (stackab->stack_a[1][0] < stackab->stack_a[1][1] &&
		stackab->stack_a[1][0] < stackab->stack_a[1][2])
	{
		rra(stackab, bench);
		sa(stackab, bench);
	}
	else
		rra(stackab, bench);
}

void	sort_five(t_stack_sct *stackab, t_bench_md *bench)
{
	int	i;

	i = 0;
	while (stackab->size_a > 3)
	{
		while (stackab->stack_a[1][0] != i)
			ra(stackab, bench);
		pb (stackab, bench);
		i++;
	}
	sort_three(stackab, bench);
	while (stackab->size_b > 0)
		pa(stackab, bench);
}

void	adaptive_mode(t_stack_sct *stackab, t_bench_md *bench)
{
	rank_indexing(stackab);
	if (stackab->size_a == 2)
		ra(stackab, bench);
	else if (stackab->size_a == 3)
		sort_three(stackab, bench);
	else if (stackab->size_a <= 5)
		sort_five(stackab, bench);
	else if (stackab->disorder < 20)
		selection_sort(stackab, bench);
	else if (stackab->disorder >= 20 && stackab->disorder < 50)
		chunk_sort(stackab, bench);
	else
		complex(stackab, bench);
}
