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

#include "push_swap.h"

int	swap_a(t_stacks *stacks, int i)
{
	int	j;
	int	swap;

	write(1, "sa\n", 3);
	j = (i + 1) % stacks->stack_a_counter;
	swap = stacks->stack_a[0][i];
	stacks->stack_a[0][i] = stacks->stack_a[0][j];
	stacks->stack_a[0][j] = swap;
	swap = stacks->stack_a[1][i];
	stacks->stack_a[1][i] = stacks->stack_a[1][j];
	stacks->stack_a[1][j] = swap;
	swap = stacks->stack_a[2][i];
	stacks->stack_a[2][i] = stacks->stack_a[2][j] + 1;
	stacks->stack_a[2][j] = swap - 1;
	return (0);
}

int	swap_b(t_stacks *stacks, int i)
{
	int	j;
	int	swap;

	if (stacks->stack_b_counter < 2)
		return (0);
	write(1, "sb\n", 3);
	j = (i + 1) % stacks->stack_b_counter;
	swap = stacks->stack_b[0][i];
	stacks->stack_b[0][i] = stacks->stack_b[0][j];
	stacks->stack_b[0][j] = swap;
	swap = stacks->stack_b[1][i];
	stacks->stack_b[1][i] = stacks->stack_b[1][j];
	stacks->stack_b[1][j] = swap;
	return (0);
}
