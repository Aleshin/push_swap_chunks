/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:55:24 by saleshin          #+#    #+#             */
/*   Updated: 2024/03/14 21:55:27 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ra(t_stacks *stacks, int rotates)
{
	print_moves("ra", rotates);
	stacks->stack_a_pointer = (stacks->stack_a_pointer + rotates)
		% stacks->stack_a_counter;
	return (0);
}

int	rra(t_stacks *stacks, int rotates_r)
{
	print_moves("rra", rotates_r);
	stacks->stack_a_pointer = stacks->stack_a_pointer - rotates_r;
	if (stacks->stack_a_pointer < 0)
		stacks->stack_a_pointer = stacks->stack_a_counter
			+ stacks->stack_a_pointer;
	return (0);
}

int	rb(t_stacks *stacks, int rotates)
{
	print_moves("rb", rotates);
	stacks->stack_b_pointer = (stacks->stack_b_pointer + rotates)
		% stacks->stack_b_counter;
	return (0);
}

int	rrb(t_stacks *stacks, int rotates_r)
{
	print_moves("rrb", rotates_r);
	stacks->stack_b_pointer = stacks->stack_b_pointer - rotates_r;
	if (stacks->stack_b_pointer < 0)
		stacks->stack_b_pointer = stacks->stack_b_counter
			+ stacks->stack_b_pointer;
	return (0);
}
