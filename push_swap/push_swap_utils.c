/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap_utils.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/29 09:57:15 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/29 09:57:16 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**make_stack(int s, char **src)
{
	int		i;
	char	**dst;

	dst = malloc(sizeof(char *) * s);
	if (!dst)
		return (NULL);
	i = 1;
	while (i < s)
	{
		dst[i - 1] = ft_strdup(src[i]);
		if (!dst[i - 1])
		{
			dst[i - 1] = NULL;
			free_stack(dst);
			return (NULL);
		}
		i++;
	}
	dst[i - 1] = NULL;
	return (dst);
}

int	*stack_atoi(char **src)
{
	int	i;
	int	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(int) * i);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = ft_atoi(src[i]);
		i++;
	}
	return (dest);
}

void	print_stack_int(t_stack_sct stackab)
{
	int	max_size;
	int	i;

	max_size = stackab.size_a;
	if (stackab.size_b > max_size)
		max_size = stackab.size_b;
	i = max_size - 1;
	while (i >= 0)
	{
		ft_printf("%d: ", i);
		if (i < stackab.size_a)
			ft_printf("A: %d (idx:%d)  ",
				stackab.stack_a[0][i], stackab.stack_a[1][i]);
		else
			ft_printf("A: -          ");
		if (i < stackab.size_b)
			ft_printf("B: %d (idx:%d)",
				stackab.stack_b[0][i], stackab.stack_b[1][i]);
		else
			ft_printf("B: -");
		ft_printf("\n");
		i--;
	}
	ft_printf("--------------------\n");
}

void	rank_indexing(t_stack_sct *stackab)
{
	int		i;
	int		j;
	int		rank;

	i = 0;
	while (i < stackab->size_a)
	{
		rank = 0;
		j = 0;
		while (j < stackab->size_a)
		{
			if (stackab->stack_a[0][i] > stackab->stack_a[0][j])
				rank++;
			j++;
		}
		stackab->stack_a[1][i] = rank;
		i++;
	}
}

int	check_smallest(t_stack_sct *stackab)
{
	int	i;
	int	min_val;
	int	min_index;

	if (stackab->size_a <= 0)
		return (0);
	min_val = stackab->stack_a[0][0];
	min_index = 0;
	i = 1;
	while (i < stackab->size_a)
	{
		if (stackab->stack_a[0][i] < min_val)
		{
			min_val = stackab->stack_a[0][i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
