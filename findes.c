/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:33:26 by saleshin          #+#    #+#             */
/*   Updated: 2024/03/06 16:33:44 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_ra(t_stacks *stacks, int chunk_no)
{
	int	rotates;
	int	pos;

	rotates = 0;
	pos = stacks->stack_a_pointer;
	while (rotates < stacks->stack_a_counter)
	{
		if (stacks->stack_a[2][pos] == chunk_no)
			return (rotates);
		else
		{
			pos = (pos + 1) % stacks->stack_a_counter;
			rotates++;
		}
	}
	return (-1);
}

int	find_rb(t_stacks *stacks, int n)
{
	int	rotates;
	int	pos;

	rotates = 0;
	pos = stacks->stack_b_pointer;
	while (rotates < stacks->stack_b_counter)
	{
		if (stacks->stack_b[1][pos] == n)
			return (rotates);
		else
		{
			pos = (pos + 1) % stacks->stack_b_counter;
			rotates++;
		}
	}
	return (-1);
}

int	find_place(t_stacks *stacks)
{
	int	i;
	int	res;
	int	pointer;
	int	min;
	int	max;

	i = 0;
	res = 0;
	pointer = stacks->stack_a_pointer;
	min = 6;
	max = -1;
	while (i < stacks->stack_a_counter)
	{
		if (stacks->stack_a[1][pointer] < stacks->stack_b[1][0])
		{
			if (stacks->stack_a[1][pointer] > max)
			{
				max = stacks->stack_a[1][pointer];
				res = i;
			}
		}
		else if (stacks->stack_a[1][pointer] < min)
		{
			min = stacks->stack_a[1][pointer];
			res = i - 1;
		}
		pointer = (pointer + 1) % stacks->stack_a_counter;
		i++;
	}
	return (++res);
}
