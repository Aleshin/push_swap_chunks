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

int	pull_a(t_stacks *stacks)
{
	int	i;

	i = stacks->stack_a_pointer;
	if (stacks->stack_a_counter <= 1)
	{
		stacks->stack_a_pointer = 0;
		stacks->stack_a_counter = 0;
		return (0);
	}
	if (i == stacks->stack_a_counter - 1 && i > 0)
	{
		stacks->stack_a_pointer = 0;
		stacks->stack_a_counter--;
		return (0);
	}
	while (i < stacks->stack_a_counter - 1)
	{
		stacks->stack_a[0][i] = stacks->stack_a[0][i + 1];
		stacks->stack_a[1][i] = stacks->stack_a[1][i + 1];
		stacks->stack_a[2][i] = stacks->stack_a[2][i + 1];
		i++;
	}
	stacks->stack_a_counter--;
	return (0);
}

int	pull_b(t_stacks *stacks)
{
	int	i;

	i = stacks->stack_b_pointer;
	if (stacks->stack_b_counter <= 1)
	{
		stacks->stack_b_pointer = 0;
		stacks->stack_b_counter = 0;
		return (0);
	}
	if (i == stacks->stack_b_counter - 1 && i > 0)
	{
		stacks->stack_b_pointer = 0;
		stacks->stack_b_counter--;
		return (0);
	}
	while (i < stacks->stack_b_counter - 1)
	{
		stacks->stack_b[0][i] = stacks->stack_b[0][i + 1];
		stacks->stack_b[1][i] = stacks->stack_b[1][i + 1];
		i++;
	}
	stacks->stack_b_counter--;
	return (0);
}

int	push_a(t_stacks *stacks)
{
	int	i;

	write(1, "pa\n", 3);
	stacks->stack_a_counter++;
	i = stacks->stack_a_counter - 1;
	while (i > stacks->stack_a_pointer)
	{
		stacks->stack_a[0][i] = stacks->stack_a[0][i - 1];
		stacks->stack_a[1][i] = stacks->stack_a[1][i - 1];
		i--;
	}
	stacks->stack_a[0][i] = stacks->stack_b[0][stacks->stack_b_pointer];
	stacks->stack_a[1][i] = stacks->stack_b[1][stacks->stack_b_pointer];
	pull_b(stacks);
	return (0);
}

int	push_b(t_stacks *stacks)
{
	int	i;

	write(1, "pb\n", 3);
	stacks->stack_b_counter++;
	i = stacks->stack_b_counter - 1;
	while (i > stacks->stack_b_pointer)
	{
		stacks->stack_b[0][i] = stacks->stack_b[0][i - 1];
		stacks->stack_b[1][i] = stacks->stack_b[1][i - 1];
		i--;
	}
	stacks->stack_b[0][i] = stacks->stack_a[0][stacks->stack_a_pointer];
	stacks->stack_b[1][i] = stacks->stack_a[1][stacks->stack_a_pointer];
	pull_a(stacks);
	return (0);
}
