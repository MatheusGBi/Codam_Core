/* ************************************************************************** */
/*																			*/
/*														 ::::::::		   */
/*   push_swap_rrr.c									 :+:	:+:		   */
/*													  +:+				   */
/*   By: mgiraldi <marvin@42.fr>					   +#+					*/
/*													+#+					 */
/*   Created: 2026/11/11 16:20:13 by mgiraldi	   #+#	#+#				*/
/*   Updated: 2026/11/11 16:20:14 by mgiraldi	   ########   odam.nl		*/
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	rrr_rra(t_stack_sct *stackab)
{
	int	i;
	int	temp0;
	int	temp1;

	i = stackab->size_a - 1;
	temp0 = stackab->stack_a[0][stackab->size_a - 1];
	temp1 = stackab->stack_a[1][stackab->size_a - 1];
	while (i > 0)
	{
		stackab->stack_a[0][i] = stackab->stack_a[0][i - 1];
		stackab->stack_a[1][i] = stackab->stack_a[1][i - 1];
		i--;
	}
	stackab->stack_a[0][i] = temp0;
	stackab->stack_a[1][i] = temp1;
}

void	rrr_rrb(t_stack_sct *stackab)
{
	int	i;
	int	temp0;
	int	temp1;

	i = stackab->size_b - 1;
	temp0 = stackab->stack_b[0][stackab->size_b - 1];
	temp1 = stackab->stack_b[1][stackab->size_b - 1];
	while (i > 0)
	{
		stackab->stack_b[0][i] = stackab->stack_b[0][i - 1];
		stackab->stack_b[1][i] = stackab->stack_b[1][i - 1];
		i--;
	}
	stackab->stack_b[0][i] = temp0;
	stackab->stack_b[1][i] = temp1;
}

void	rrr(t_stack_sct *stackab, t_bench_md *bench)
{
	if (stackab->size_a < 2 || stackab->size_b < 2)
		return ;
	if (bench->on_off == 1)
		bench->op[10]++;
	rrr_rra(stackab);
	rrr_rrb(stackab);
	ft_printf("rrr\n");
}
