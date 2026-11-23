/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_bench.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/09 13:19:11 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/09 13:19:13 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	strat(int strategy)
{
	if (strategy == 0)
		ft_putstr_fd("[bench] Strategy: Simple\n", 2);
	else if (strategy == 1)
		ft_putstr_fd("[bench] Strategy: Medium\n", 2);
	else if (strategy == 2)
		ft_putstr_fd("[bench] Strategy: Complex\n", 2);
	else if (strategy == 3)
		ft_putstr_fd("[bench] Strategy: Adaptive\n", 2);
}

void	print_op(int *op)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(op[0], 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(op[1], 2);
	ft_putstr_fd("  ra:  ", 2);
	ft_putnbr_fd(op[2], 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(op[3], 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sb:  ", 2);
	ft_putnbr_fd(op[4], 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(op[5], 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(op[6], 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(op[7], 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ss:  ", 2);
	ft_putnbr_fd(op[8], 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(op[9], 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(op[10], 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench_md bench, int disorder, int strategy)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	if (bench.on_off == 0)
		return ;
	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putnbr_fd(disorder, 2);
	ft_putstr_fd("%", 2);
	ft_putstr_fd("\n", 2);
	strat(strategy);
	while (i < 11)
	{
		total = total + bench.op[i];
		i++;
	}
	ft_putstr_fd("[bench] Total Operations: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_op(bench.op);
}
