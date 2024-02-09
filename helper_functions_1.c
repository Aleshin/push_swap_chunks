/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:00:28 by saleshin          #+#    #+#             */
/*   Updated: 2023/08/14 18:34:19 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_position_b(t_stacks *stacks, int a_pointer)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (i < stacks->stack_b_counter)
	{
		if (stacks->stack_a[1][a_pointer] > stacks->stack_b[1][i])
		{
			if (i + 1 < stacks->stack_b_counter)
				m = i + 1;
			else
				m = -1;
		}
		i++;
	}
	return (m);
}

int	find_moves_b(t_stacks *stacks, int p)
{
	int	i;
	int	n;
	int	m;

	i = stacks->stack_b_pointer;
	n = stacks->b_counter;
	if ((i <= p && p - i <= n / 2) || (i >= p && i - p <= n / 2))
		m = p - i;
	else if (i < p)
		m = -i - n + p;
	else
		m = n - i + p;
	return (m);
}

int	move_b_pointer(t_stacks *stacks, int m)
{
	int	i;

	i = 0;
	if (m > 0)
	{
		while (i++ < m)
		rotate_b(stacks, 1);
	}
	else if (m < 0)
	{
		while (i++ < -m)
		rotate_b(stacks, -1);
	}
	return (0);
}

int push_a_2_b(t_stacks *stacks)
{
	int	m;

	m = find_position_b(stacks, stacks->stack_a_pointer);
	if (m == -1)
	{
//		printf("pos = %d, pointer = %d, moves = %d, counter = %d\n",
//			m, stacks->stack_b_pointer, find_moves_b(stacks, stacks->stack_b_counter - 1), stacks->stack_b_counter);
		move_b_pointer(stacks, find_moves_b(stacks, stacks->stack_b_counter - 1));
		push_b(stacks, stacks->stack_a_pointer);
		swap_b(stacks, stacks->stack_b_pointer);
	}
	else
	{
//		printf("pos = %d, pointer = %d, moves = %d, counter = %d\n",
//			m, stacks->stack_b_pointer, find_moves_b(stacks, m), stacks->stack_b_counter);
		move_b_pointer(stacks, find_moves_b(stacks, m));
		push_b(stacks, stacks->stack_a_pointer);
	}
	return (0);
}
