/* ************************************************************************** */
/*					*/
/*			   ::::::::  */
/*   push_swap_a.c		   :+:  :+:	*/
/*			  +:+	  */
/*   By: mgiraldi <marvin@42.fr>					   +#+	  */
/*			  +#+	*/
/*   Created: 2026/11/09 13:12:24 by mgiraldi	 #+# #+#	*/
/*   Updated: 2026/11/09 13:12:35 by mgiraldi	 ########   odam.nl   */
/*					*/
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_sct *stackab, t_bench_md *bench)
{
	int	temp0;
	int	temp1;

	if (stackab->size_a < 2)
		return ;
	temp0 = stackab->stack_a[0][0];
	temp1 = stackab->stack_a[1][0];
	stackab->stack_a[0][0] = stackab->stack_a[0][1];
	stackab->stack_a[1][0] = stackab->stack_a[1][1];
	stackab->stack_a[0][1] = temp0;
	stackab->stack_a[1][1] = temp1;
	if (bench->on_off == 1)
		bench->op[0]++;
	ft_printf("sa\n");
}

void	pa(t_stack_sct *s, t_bench_md *bench)
{
	int	i;

	if (s->size_b <= 0)
		return ;
	i = s->size_a;
	while (i > 0)
	{
		s->stack_a[0][i] = s->stack_a[0][i - 1];
		s->stack_a[1][i] = s->stack_a[1][i - 1];
		i--;
	}
	s->stack_a[0][0] = s->stack_b[0][0];
	s->stack_a[1][0] = s->stack_b[1][0];
	i = 0;
	while (i < s->size_b - 1)
	{
		s->stack_b[0][i] = s->stack_b[0][i + 1];
		s->stack_b[1][i] = s->stack_b[1][i + 1];
		i++;
	}
	s->size_b--;
	s->size_a++;
	if (bench->on_off == 1)
		bench->op[1]++;
	ft_printf("pa\n");
}

void	ra(t_stack_sct *stackab, t_bench_md *bench)
{
	int	i;
	int	temp0;
	int	temp1;

	if (stackab->size_a < 2)
		return ;
	i = 0;
	temp0 = stackab->stack_a[0][i];
	temp1 = stackab->stack_a[1][i];
	while (i < stackab->size_a - 1)
	{
		stackab->stack_a[0][i] = stackab->stack_a[0][i + 1];
		stackab->stack_a[1][i] = stackab->stack_a[1][i + 1];
		i++;
	}
	stackab->stack_a[0][stackab->size_a - 1] = temp0;
	stackab->stack_a[1][stackab->size_a - 1] = temp1;
	if (bench->on_off == 1)
		bench->op[2]++;
	ft_printf("ra\n");
}

void	rra(t_stack_sct *stackab, t_bench_md *bench)
{
	int	i;
	int	temp0;
	int	temp1;

	if (stackab->size_a < 2)
		return ;
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
	if (bench->on_off == 1)
		bench->op[3]++;
	ft_printf("rra\n");
}
