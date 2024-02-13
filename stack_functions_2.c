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
	if (stacks->stack_a[0][0] > stacks->stack_a[0][1])
	{
		if (stacks->stack_a[0][1] > stacks->stack_a[0][2])
		{
			swap_a(stacks, stacks->stack_a_pointer);
			rotate_a(stacks, -1);
		}
		else if (stacks->stack_a[0][0] > stacks->stack_a[0][2])
			rotate_a(stacks, 1);
		else
			swap_a(stacks, stacks->stack_a_pointer);
	}
	else if (stacks->stack_a[0][1] > stacks->stack_a[0][2])
		{
			if (stacks->stack_a[0][0] > stacks->stack_a[0][2])
				rotate_a(stacks, -1);
			else
			{
				rotate_a(stacks, -1);
				swap_a(stacks, stacks->stack_a_pointer);
			}
		}
	return (0);
}

int	four_n(t_stacks *stacks)
{
	push_a_2_b(stacks);
	three_n(stacks);
	push_b_2_a(stacks);
	pointer_a_2_min(stacks);
	return (0);
}

int	five_n(t_stacks *stacks)
{
	print_ab(stacks);
	push_a_2_b(stacks);
	print_ab(stacks);
	push_a_2_b(stacks);
	print_ab(stacks);
	three_n(stacks);
	print_ab(stacks);
	pointer_b_2_max(stacks);
	print_ab(stacks);
	push_b_2_a(stacks);
	print_ab(stacks);
	push_b_2_a(stacks);
	print_ab(stacks);
	pointer_a_2_min(stacks);
	print_ab(stacks);
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

	return (0);
}

int	rotate_a(t_stacks *stacks, int direction)
{
	int	i;

	i = 0;
	if (direction > 0)
		write(1, "ra\n", 3);
	else
		write(1, "rra\n", 4);
	while (i < stacks->stack_a_counter)
	{
		stacks->stack_a[2][i] = stacks->stack_a[2][i] + direction;
		i++;
	}
	stacks->stack_a_pointer = stacks->stack_a_pointer + direction;
	if (stacks->stack_a_pointer == stacks->stack_a_counter)
		stacks->stack_a_pointer = 0;
	if (stacks->stack_a_pointer == -1)
		stacks->stack_a_pointer = stacks->stack_a_counter - 1;
	return (0);
}

int	rotate_b(t_stacks *stacks, int direction)
{
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
//	printf("min = %d\n", stacks->stack_a[0][m]);
	move_a_pointer(stacks, find_moves_a(stacks, m));
	return (0);
}

int	pointer_b_2_max(t_stacks *stacks)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (i < stacks->stack_b_counter)
	{
		if (stacks->stack_b[0][m] < stacks->stack_b[0][i])
			m = i;
		i++;
	}
//	printf("min = %d\n", stacks->stack_a[0][m]);
	move_b_pointer(stacks, find_moves_b(stacks, m));
	return (0);
}
