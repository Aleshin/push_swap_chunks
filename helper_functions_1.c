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
	if (m == -1)
	{
		stacks->stack_b_pointer = stacks->stack_b_counter - 1;
		push_b(stacks, a_pointer);
		swap_b(stacks, stacks->stack_b_pointer);
	}
	else
	{
		stacks->stack_b_pointer = m;
		push_b(stacks, a_pointer);
	}
	return (m);
}

int	find_moves_b(t_stacks *stacks, int a_pointer)
{
	int	i;
	int	j;
	int	n;
	int	m;

	j = stacks->stack_a[1][a_pointer];
	i = stacks->stack_b_pointer;
	n = stacks->b_counter;
	if ((i <= j && j - i <= n / 2) || (i >= j && i - j <= n / 2))
		m = j - i;
	else if (i < j)
		m = -i - n + j;
	else
		m = n - i + j;
	return (m);
}

int	find_real_moves_b(t_stacks *stacks, int a_pointer)
{
	int	i;
	int	m;
	int	sign;

	i = 0;
	sign = 1;
	m = find_moves_b(stacks, a_pointer);
	if (m < 0)
		sign = -1;
//	while ()
	return (m);
}
