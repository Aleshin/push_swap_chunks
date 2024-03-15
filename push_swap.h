/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:43:12 by saleshin          #+#    #+#             */
/*   Updated: 2023/11/18 08:43:31 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stacks
{
	int	stack_a_counter;
	int	stack_b_counter;
	int	stack_a_pointer;
	int	stack_b_pointer;
	int	chunks;
	int	chunk_size;
	int	numbers;
	int	**stack_a;
	int	**stack_b;
}	t_stacks;

int	make_array(int ***array, int i, int j);
int	create_arrays(t_stacks *stacks, int j);
int	input_data(t_stacks *stacks, int argc, char **argv);
int	ft_atoi(const char *str, t_stacks *stacks);
int	special_cases(t_stacks *stacks, int args);
int	chunk_size(t_stacks *stacks);
int	scan_chank(t_stacks *stacks, int n);
int	find_num_in_chunk(t_stacks *stacks, int chunk_no);
int	find_ra(t_stacks *stacks, int chunk_no);
int	find_rra(t_stacks *stacks, int chunk_no);
int	find_ra_4(t_stacks *stacks, int chunk_no);
int	find_rra_4(t_stacks *stacks, int chunk_no);
int	find_rb(t_stacks *stacks, int n);
int	find_rrb(t_stacks *stacks, int n);
int	ra(t_stacks *stacks, int rotates);
int	rra(t_stacks *stacks, int rotates_r);
int	rb(t_stacks *stacks, int rotates);
int	rrb(t_stacks *stacks, int rotates_r);
int	find_chunks(t_stacks *stacks);
int	scan_a(t_stacks *stacks);
int	scan_b(t_stacks *stacks);
int	pull_a(t_stacks *stacks);
int	pull_b(t_stacks *stacks);
int	push_all(t_stacks *stacks);
int	push_a(t_stacks *stacks);
int	push_b(t_stacks *stacks);
int	rotate_a(t_stacks *stacks, int direction);
int	rotate_b(t_stacks *stacks, int direction);
int	swap_a(t_stacks *stacks, int i);
int	swap_b(t_stacks *stacks, int i);
int	init(t_stacks *stacks);
int	ft_strlen(char *str);
int	print(t_stacks *stacks);
int	print_moves(char *str, int c);
int	print_ab(t_stacks *stacks);
int	bubble_sort(t_stacks *stacks);
int	find_moves(t_stacks *stacks);
int	pointer_a_2_min(t_stacks *stacks);
int	pointer_b_2_max(t_stacks *stacks);
int	find_real_moves_b(t_stacks *stacks, int a_pointer);
int	three_n(t_stacks *stacks);
int	four_n(t_stacks *stacks);
int	five_n(t_stacks *stacks);
#endif
