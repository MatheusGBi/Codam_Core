/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_utils3.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/11/16 14:54:14 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/11/16 14:54:34 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

void	free_t_stack(t_stack_sct *stackab)
{
	free(stackab->stack_a[0]);
	free(stackab->stack_a[1]);
	free(stackab->stack_a);
	free(stackab->stack_b[0]);
	free(stackab->stack_b[1]);
	free(stackab->stack_b);
}

int	**build_stack(char **stack)
{
	int	**stack_a;
	int	size;

	size = 0;
	while (stack[size])
		size++;
	stack_a = malloc(sizeof(int *) * 2);
	if (!stack_a)
		return (NULL);
	stack_a[0] = stack_atoi(stack);
	stack_a[1] = malloc(sizeof(int) * size);
	if (!stack_a[0] || !stack_a[1])
	{
		free(stack_a[0]);
		free(stack_a[1]);
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
}
