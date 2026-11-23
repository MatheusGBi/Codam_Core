/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_utils2.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/13 17:17:21 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/13 17:17:31 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**arg_check(int argc, char **argv)
{
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (make_stack(argc, argv));
}

int	stack_size(int argc, char **argv)
{
	char	**stack;
	int		size;

	stack = arg_check(argc, argv);
	if (!stack)
		return (0);
	size = 0;
	while (stack[size])
		size++;
	free_stack(stack);
	return (size);
}

int	is_sorted(t_stack_sct *stackab)
{
	int	i;

	i = 0;
	while (i < stackab->size_a - 1)
	{
		if (stackab->stack_a[0][i] > stackab->stack_a[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (1);
	i = 1;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

int	check_shortest_path(t_stack_sct *stackab, int min, int max)
{
	int	count_ra;
	int	count_rra;
	int	i;

	count_ra = 0;
	count_rra = 0;
	i = 0;
	while (i < stackab->size_a && (stackab->stack_a[1][i] < min
		|| stackab->stack_a[1][i] >= max))
	{
		i++;
		count_ra++;
	}
	i = stackab->size_a - 1;
	while (i >= 0 && (stackab->stack_a[1][i] < min
		|| stackab->stack_a[1][i] >= max))
	{
		i--;
		count_rra++;
	}
	return (count_ra <= count_rra + 1);
}
