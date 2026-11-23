/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_b.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/09 13:12:46 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/09 13:15:41 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack_sct *stackab, t_bench_md *bench)
{
	int	temp0;
	int	temp1;

	if (stackab->size_b < 2)
		return ;
	temp0 = stackab->stack_b[0][0];
	temp1 = stackab->stack_b[1][0];
	stackab->stack_b[0][0] = stackab->stack_b[0][1];
	stackab->stack_b[1][0] = stackab->stack_b[1][1];
	stackab->stack_b[0][1] = temp0;
	stackab->stack_b[1][1] = temp1;
	if (bench->on_off == 1)
		bench->op[4]++;
	ft_printf("sb\n");
}

void	pb(t_stack_sct *s, t_bench_md *bench)
{
	int	i;

	if (s->size_a <= 0)
		return ;
	i = s->size_b;
	while (i > 0)
	{
		s->stack_b[0][i] = s->stack_b[0][i - 1];
		s->stack_b[1][i] = s->stack_b[1][i - 1];
		i--;
	}
	s->stack_b[0][0] = s->stack_a[0][0];
	s->stack_b[1][0] = s->stack_a[1][0];
	i = 0;
	while (i < s->size_a - 1)
	{
		s->stack_a[0][i] = s->stack_a[0][i + 1];
		s->stack_a[1][i] = s->stack_a[1][i + 1];
		i++;
	}
	s->size_a--;
	s->size_b++;
	if (bench->on_off == 1)
		bench->op[5]++;
	ft_printf("pb\n");
}

void	rb(t_stack_sct *stackab, t_bench_md *bench)
{
	int	i;
	int	temp0;
	int	temp1;

	if (stackab->size_b < 2)
		return ;
	temp0 = stackab->stack_b[0][0];
	temp1 = stackab->stack_b[1][0];
	i = 0;
	while (i < stackab->size_b - 1)
	{
		stackab->stack_b[0][i] = stackab->stack_b[0][i + 1];
		stackab->stack_b[1][i] = stackab->stack_b[1][i + 1];
		i++;
	}
	stackab->stack_b[0][stackab->size_b - 1] = temp0;
	stackab->stack_b[1][stackab->size_b - 1] = temp1;
	if (bench->on_off == 1)
		bench->op[6]++;
	ft_printf("rb\n");
}

void	rrb(t_stack_sct *stackab, t_bench_md *bench)
{
	int	i;
	int	temp0;
	int	temp1;

	if (stackab->size_b < 2)
		return ;
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
	if (bench->on_off == 1)
		bench->op[7]++;
	ft_printf("rrb\n");
}
