/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push_swap.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/29 09:56:50 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/29 09:56:59 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**argcheck(int argc, char **argv)
{
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (make_stack(argc, argv));
}

int	**argstack(int argc, char **argv)
{
	char	**stack;
	int		**stack_a;

	stack = argcheck(argc, argv);
	if (!stack || !stack_validity(stack))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack);
		return (NULL);
	}
	stack_a = build_stack(stack);
	free_stack(stack);
	return (stack_a);
}

void	handle_flags(int *argc, char ***argv, int *strategy, t_bench_md *bench)
{
	bench->on_off = 0;
	*strategy = 3;
	while (*argc > 1)
	{
		if (ft_strcmp((*argv)[1], "--bench") == 0)
			bench->on_off = 1;
		else if (ft_strcmp((*argv)[1], "--simple") == 0)
			*strategy = 0;
		else if (ft_strcmp((*argv)[1], "--medium") == 0)
			*strategy = 1;
		else if (ft_strcmp((*argv)[1], "--complex") == 0)
			*strategy = 2;
		else if (ft_strcmp((*argv)[1], "--adaptive") == 0)
			*strategy = 3;
		else
			break ;
		(*argv)++;
		(*argc)--;
	}
}

void	strg_sct(t_stack_sct *stackab, t_bench_md *bench, int strategy)
{
	if (is_sorted(stackab))
		return ;
	else if (strategy == 0)
		selection_sort(stackab, bench);
	else if (strategy == 1)
		chunk_sort(stackab, bench);
	else if (strategy == 2)
		complex(stackab, bench);
	else if (strategy == 3)
		adaptive_mode(stackab, bench);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack_sct		stackab;
	int				strategy;
	t_bench_md		bench;
	int				size;
	int				**stack;

	handle_flags(&argc, &argv, &strategy, &bench);
	if (argc < 2)
		return (0);
	ft_bzero(bench.op, sizeof(int) * 11);
	size = stack_size(argc, argv);
	stack = argstack(argc, argv);
	if (!stack)
		return (1);
	if (!stack_create(&stackab, stack, size))
	{
		free(stack[0]);
		free(stack[1]);
		free(stack);
		return (1);
	}
	strg_sct(&stackab, &bench, strategy);
	free_t_stack(&stackab);
	print_bench(bench, stackab.disorder, strategy);
	return (0);
}
