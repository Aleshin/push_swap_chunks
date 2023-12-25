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

int	pull_a(t_stacks *stacks, int i)
{
	while (i < stacks->stack_a_counter - 1)
	{
		stacks->stack_a[i][0] = stacks->stack_a[i + 1][0];
		stacks->stack_a[i][1] = stacks->stack_a[i + 1][1];
		stacks->stack_a[i][2] = stacks->stack_a[i + 1][2];
		if (stacks->stack_a[i][2] > 0)
			stacks->stack_a[i][2]--;
		if (stacks->stack_a[i][2] < 0)
			stacks->stack_a[i][2]++;
		i++;
	}
	(stacks->stack_a_counter)--;
	return (0);
}

int	push_b(t_stacks *stacks, int j)
{
	int	i;

	(stacks->stack_b_pointer)++;
	(stacks->stack_b_counter)++;
	i = stacks->stack_b_counter;
	while (i > stacks->stack_b_pointer)
	{
		stacks->stack_b[i][0] = stacks->stack_b[i - 1][0];
		stacks->stack_b[i][1] = stacks->stack_b[i - 1][1];
		i--;
	}
	stacks->stack_b[i][0] = stacks->stack_a[j][0];
	stacks->stack_b[i][1] = stacks->stack_a[j][1];
	return (0);
}

int	rotate(t_stacks *stacks, int direction)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a_counter)
	{
		stacks->stack_a[i][2] = stacks->stack_a[i][2] + direction;
		i++;
	}
	return (0);
}

int	swap_a(t_stacks *stacks, int i)
{
	int	j;
	int	swap;

	if (i == stacks->stack_a_counter - 1)
		j = 0;
	else
		j = i + 1;
	if (stacks->stack_a[i][2] > 0 && stacks->stack_a[j][2] < 0)
	{
		swap = stacks->stack_a[i][0];
		stacks->stack_a[i][0] = stacks->stack_a[j][0];
		stacks->stack_a[j][0] = swap;
		swap = stacks->stack_a[i][1];
		stacks->stack_a[i][1] = stacks->stack_a[j][1];
		stacks->stack_a[j][1] = swap;
		swap = stacks->stack_a[i][2];
		stacks->stack_a[i][2] = stacks->stack_a[j][2] + 1;
		stacks->stack_a[j][2] = swap - 1;
	}
	return (0);
}
