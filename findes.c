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

int	find_rra(t_stacks *stacks, int chunk_no)
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
			pos--;
			if (pos == -1)
				pos = stacks->stack_a_counter - 1;
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

int	find_rrb(t_stacks *stacks, int n)
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
			pos--;
			if (pos == -1)
				pos = stacks->stack_b_counter - 1;
			rotates++;
		}
	}
	return (-1);
}
