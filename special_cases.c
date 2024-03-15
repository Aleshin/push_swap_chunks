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

int	three_n(t_stacks *stacks)
{
	if (stacks->stack_a[0][0] < stacks->stack_a[0][1])
	{
		if (stacks->stack_a[0][1] < stacks->stack_a[0][2])
			return (0);
		else if (stacks->stack_a[0][0] < stacks->stack_a[0][2])
			write(1, "rra\nsa\n", 7);
		else
			write (1, "rra\n", 4);
	}
	else if (stacks->stack_a[0][0] < stacks->stack_a[0][2])
		write(1, "sa\n", 3);
	else if (stacks->stack_a[0][1] < stacks->stack_a[0][2])
		write(1, "ra\n", 3);
	else
		write(1, "ra\nsa\n", 6);
	return (0);
}

int	four_n(t_stacks *stacks)
{
	push_b(stacks);
	three_n(stacks);
	if (stacks->stack_b[1][0] < 2)
	{
		ra(stacks, stacks->stack_b[1][0]);
		push_a(stacks);
		rra(stacks, stacks->stack_b[1][0]);
	}
	else if (stacks->stack_b[1][0] == 2)
	{
		rra(stacks, 1);
		push_a(stacks);
		ra(stacks, 2);
	}
	else
	{
		push_a(stacks);
		ra(stacks, 1);
	}
	return (0);
}

int	five_n(t_stacks *stacks)
{
	(void)stacks;
/*
	push_a_2_b(stacks);
	push_a_2_b(stacks);
	three_n(stacks);
	push_b_2_a(stacks);
	push_b_2_a(stacks);
*/
	return (0);
}

int	special_cases(t_stacks *stacks, int args)
{
	if (args == 1)
		return (1);
	if (args == 2)
	{
		if (stacks->stack_a[0][0] > stacks->stack_a[0][1])
			write(1, "sa\n", 3);
		return (1);
	}
	if (args == 3)
	{
		three_n(stacks);
		return (1);
	}
	if (args == 4)
	{
		four_n(stacks);
		return (1);
	}
	if (args == 5)
	{
		four_n(stacks);
		return (1);
	}
	find_chunks(stacks);
	return (0);
}
