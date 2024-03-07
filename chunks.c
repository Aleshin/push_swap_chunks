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

int	scan_a(t_stacks *stacks)
{
	int	n;

	n = 0;
	while (n < stacks->chunks)
	{
		find_num_in_chunk(stacks, n++);
	}
	return (0);
}

int	find_num_in_chunk(t_stacks *stacks, int chunk_no)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a_counter)
	{
		if (stacks->stack_a[2][i] == chunk_no)
		{
			push_b(stacks, i);
		}
		else
			i++;
	}
	return (0);
}

int	scan_b(t_stacks *stacks)
{
	int	i;
	int	j;

	i = stacks->numbers - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < stacks->stack_b_counter)
		{
			if (stacks->stack_b[1][j] == i)
			{
				push_a(stacks, j);
			}
			else
				j++;
		}
		i--;
	}
	return (0);
}
