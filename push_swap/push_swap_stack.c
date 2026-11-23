/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_stack.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/12 13:27:51 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/12 13:28:00 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	mistakes_ctr(int *stack, int len, int dis[2])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	ft_bzero(dis, sizeof(int) * 2);
	while (i < (len - 1))
	{
		j = i + 1;
		while (j < len)
		{
			dis[1]++;
			if (stack[i] > stack[j])
				dis[0]++;
			j++;
		}
		i++;
	}
}

int	compute_disorder(int *stack, int size)
{
	int		dis[2];

	if (!stack)
		return (0);
	mistakes_ctr(stack, size, dis);
	if (dis[1] == 0)
		return (0);
	return ((dis[0] * 100) / dis[1]);
}

int	stack_create(t_stack_sct *stackab, int **stack, int size)
{
	stackab->disorder = compute_disorder(stack[0], size);
	stackab->stack_a = stack;
	stackab->size_a = size;
	stackab->size_b = 0;
	stackab->stack_b = malloc(sizeof(int *) * 2);
	if (!stackab->stack_b)
		return (0);
	stackab->stack_b[0] = malloc(sizeof(int) * size);
	stackab->stack_b[1] = malloc(sizeof(int) * size);
	if (!stackab->stack_b[0] || !stackab->stack_b[1])
	{
		free(stackab->stack_b[0]);
		free(stackab->stack_b[1]);
		free(stackab->stack_b);
		return (0);
	}
	return (1);
}
