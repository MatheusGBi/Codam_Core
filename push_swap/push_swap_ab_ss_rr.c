/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap_swap.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mojonker <mojonker@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/11/04 11:58:20 by mojonker		  #+#	#+#			 */
/*   Updated: 2026/11/05 17:30:19 by mojonker		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "push_swap.h"

void	ss(t_stack_sct *stackab, t_bench_md *bench)
{
	int	temp0;
	int	temp1;

	if (stackab->size_a < 2 || stackab->size_b < 2)
		return ;
	temp0 = stackab->stack_a[0][0];
	temp1 = stackab->stack_a[1][0];
	stackab->stack_a[0][0] = stackab->stack_a[0][1];
	stackab->stack_a[1][0] = stackab->stack_a[1][1];
	stackab->stack_a[0][1] = temp0;
	stackab->stack_a[1][1] = temp1;
	temp0 = stackab->stack_b[0][0];
	temp1 = stackab->stack_b[1][0];
	stackab->stack_b[0][0] = stackab->stack_b[0][1];
	stackab->stack_b[1][0] = stackab->stack_b[1][1];
	stackab->stack_b[0][1] = temp0;
	stackab->stack_b[1][1] = temp1;
	if (bench->on_off == 1)
		bench->op[8]++;
	ft_printf("ss\n");
}

void	rr_ra(t_stack_sct *stackab)
{
	int	i;
	int	temp0;
	int	temp1;

	i = 0;
	temp0 = stackab->stack_a[0][0];
	temp1 = stackab->stack_a[1][0];
	while (i < stackab->size_a - 1)
	{
		stackab->stack_a[0][i] = stackab->stack_a[0][i + 1];
		stackab->stack_a[1][i] = stackab->stack_a[1][i + 1];
		i++;
	}
	stackab->stack_a[0][stackab->size_a - 1] = temp0;
	stackab->stack_a[1][stackab->size_a - 1] = temp1;
}

void	rr_rb(t_stack_sct *stackab)
{
	int	i;
	int	temp0;
	int	temp1;

	i = 0;
	temp0 = stackab->stack_b[0][0];
	temp1 = stackab->stack_b[1][0];
	while (i < stackab->size_b - 1)
	{
		stackab->stack_b[0][i] = stackab->stack_b[0][i + 1];
		stackab->stack_b[1][i] = stackab->stack_b[1][i + 1];
		i++;
	}
	stackab->stack_b[0][stackab->size_b - 1] = temp0;
	stackab->stack_b[1][stackab->size_b - 1] = temp1;
}

void	rr(t_stack_sct *stackab, t_bench_md *bench)
{
	if (stackab->size_a < 2 || stackab->size_b < 2)
		return ;
	if (bench->on_off == 1)
		bench->op[9]++;
	rr_ra(stackab);
	rr_rb(stackab);
	ft_printf("rr\n");
}
