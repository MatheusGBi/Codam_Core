/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojonker <mojonker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:07:56 by mgiraldi          #+#    #+#             */
/*   Updated: 2026/11/04 11:59:00 by mojonker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct t_bench_mode
{
	int		on_off;
	int		op[11];	
}	t_bench_md;
typedef struct t_stack_ps
{
	int		disorder;
	int		**stack_a;
	int		size_a;
	int		**stack_b;
	int		size_b;	
}	t_stack_sct;
int				stack_create(t_stack_sct *stackab, int **stack, int size);
int				compute_disorder(int *stack, int size);
char			**make_stack(int s, char **src);
int				*stack_atoi(char **src);
int				stack_validity(char **stack);
int				ft_strcmp(char *s1, char *s2);
void			print_stack_int(t_stack_sct stackab);
void			free_stack(char **src);
void			selection_sort(t_stack_sct *stackab, t_bench_md *bench);
void			sa(t_stack_sct *stackab, t_bench_md *bench);
void			sb(t_stack_sct *stackab, t_bench_md *bench);
void			ss(t_stack_sct *stackab, t_bench_md *bench);
void			pa(t_stack_sct *stackab, t_bench_md *bench);
void			pb(t_stack_sct *stackab, t_bench_md *bench);
void			ra(t_stack_sct *stackab, t_bench_md *bench);
void			rb(t_stack_sct *stackab, t_bench_md *bench);
void			rr(t_stack_sct *stackab, t_bench_md *bench);
void			rra(t_stack_sct *stackab, t_bench_md *bench);
void			rrb(t_stack_sct *stackab, t_bench_md *bench);
void			rrr(t_stack_sct *stackab, t_bench_md *bench);
void			rank_indexing(t_stack_sct *stackab);
void			print_bench(t_bench_md bench, int disorder, int strategy);
int				check_smallest(t_stack_sct *stackab);
void			chunk_sort(t_stack_sct *stackab, t_bench_md *bench);
int				stack_size(int argc, char **argv);
int				is_sorted(t_stack_sct *stackab);
int				ft_sqrt(int n);
void			complex(t_stack_sct *stackab, t_bench_md *bench);
int				check_shortest_path(t_stack_sct *stackab, int min, int max);
void			adaptive_mode(t_stack_sct *stackab, t_bench_md *bench);
void			free_stack(char **stack);
void			free_t_stack(t_stack_sct *stackab);
int				**build_stack(char **stack);

#endif