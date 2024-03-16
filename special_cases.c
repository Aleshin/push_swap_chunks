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
		{
			rra(stacks, 1);
			swap_a(stacks, stacks->stack_a_pointer);
		}
		else
			rra(stacks, 1);
	}
	else if (stacks->stack_a[0][0] < stacks->stack_a[0][2])
		swap_a(stacks, stacks->stack_a_pointer);
	else if (stacks->stack_a[0][1] < stacks->stack_a[0][2])
		ra(stacks, 1);
	else
	{
		ra(stacks, 1);
		swap_a(stacks, stacks->stack_a_pointer);
	}
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
	int	pointer;

	push_b(stacks);
	push_b(stacks);
	three_n(stacks);
	if (find_place(stacks) <= stacks->stack_a_counter / 2)
		ra(stacks, find_place(stacks));
	else
		rra(stacks, stacks->stack_a_counter - find_place(stacks));
	push_a(stacks);
	if (find_place(stacks) <= stacks->stack_a_counter / 2)
		ra(stacks, find_place(stacks));
	else
		rra(stacks, stacks->stack_a_counter - find_place(stacks));
	push_a(stacks);
	pointer = stacks->stack_a[1][stacks->stack_a_pointer];
	if (pointer <= stacks->stack_a_counter / 2)
		rra(stacks, pointer);
	else
		ra(stacks, stacks->stack_a_counter - pointer);
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
		five_n(stacks);
		return (1);
	}
	find_chunks(stacks);
	return (0);
}
