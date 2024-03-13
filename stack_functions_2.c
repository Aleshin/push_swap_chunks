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
//	int	i;
	push_a_2_b(stacks);
//	print(stacks);
	three_n(stacks);
//	print(stacks);
	push_b_2_a(stacks);
	pointer_a_2_min(stacks);
//	print(stacks);
/*
	while (i < stacks.stack_a_counter)
	{
		push_a_2_b(&stacks);
		i++;
		stacks.stack_a_pointer++;
	}
*/
	return (0);
}

int	five_n(t_stacks *stacks)
{
	push_a_2_b(stacks);
	push_a_2_b(stacks);
	three_n(stacks);
	push_b_2_a(stacks);
	push_b_2_a(stacks);
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

int	rotate_a(t_stacks *stacks, int direction)
{
	int	i;

	i = 0;
	if (direction > 0)
		write(1, "rra\n", 4);
	else
		write(1, "ra\n", 3);
	while (i < stacks->stack_a_counter)
	{
		stacks->stack_a[2][i] = stacks->stack_a[2][i] + direction;
		i++;
	}
	stacks->stack_a_pointer = (stacks->stack_a_pointer + direction)
		% stacks->stack_a_counter;
	if (stacks->stack_a_pointer < 0)
		stacks->stack_a_pointer = stacks->stack_a_counter;
	return (0);
}

int	rotate_b(t_stacks *stacks, int direction)
{
    if (stacks->stack_b_counter < 2)
        return (0);
	if (direction > 0)
		write(1, "rb\n", 3);
	else
		write(1, "rrb\n", 4);
	stacks->stack_b_pointer = (stacks->stack_b_pointer + direction)
		% stacks->stack_b_counter;
	if (stacks->stack_b_pointer < 0)
		stacks->stack_b_pointer = stacks->stack_b_counter - 1;
	return (0);
}

int	push_all(t_stacks *stacks)
{
	int	i;

	i = 0;
	move_b_pointer(stacks, find_moves_b(stacks, 0));
	stacks->stack_a_counter = stacks->stack_b_counter;
	stacks->stack_a_pointer = 0;
	while (i < stacks->stack_b_counter)
	{
		write(1, "pa\n", 3);
		stacks->stack_a[0][i] = stacks->stack_b[0][stacks->stack_a_counter - i - 1];
		stacks->stack_a[1][i] = stacks->stack_b[1][i];
		stacks->stack_a[2][i] = 0;
		i++;
	}
	return (0);
}

int	pointer_a_2_min(t_stacks *stacks)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (i < stacks->stack_a_counter)
	{
		if (stacks->stack_a[0][m] > stacks->stack_a[0][i])
			m = i;
		i++;
	}
	move_a_pointer(stacks, find_moves_a(stacks, m));
	return (0);
}
