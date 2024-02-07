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
		stacks->stack_a[0][i] = stacks->stack_a[0][i + 1];
		stacks->stack_a[1][i] = stacks->stack_a[1][i + 1];
		stacks->stack_a[2][i] = stacks->stack_a[2][i + 1];
		if (stacks->stack_a[2][i] > 0)
			stacks->stack_a[2][i]--;
		if (stacks->stack_a[2][i] < 0)
			stacks->stack_a[2][i]++;
		i++;
	}
	(stacks->stack_a_counter)--;
	return (0);
}

int	push_b(t_stacks *stacks, int j)
{
	int	i;

	stacks->stack_b_counter++;
	i = stacks->stack_b_counter - 1;
	while (i > stacks->stack_b_pointer)
	{
		stacks->stack_b[0][i] = stacks->stack_b[0][i - 1];
		stacks->stack_b[1][i] = stacks->stack_b[1][i - 1];
		i--;
	}
	stacks->stack_b[0][i] = stacks->stack_a[0][j];
	stacks->stack_b[1][i] = stacks->stack_a[1][j];
/*
	int	i;

	i = 0;
	if (stacks->stack_b_counter > 0)
	{
		while (i < stacks->stack_b_counter)
		{
			if (stacks->stack_b[0][stacks->stack_b_pointer] < stacks->stack_a[0][j])
		}
	}
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

	stacks->stack_b[0][stacks->stack_a[1][j]] = stacks->stack_a[0][j];
	stacks->stack_b[1][stacks->stack_a[1][j]] = stacks->stack_a[1][j];
*/
	return (0);
}

int	swaps_pushes(t_stacks *stacks)
{
	int	j;
	int	n;
	int	m;
	int	res;

	j = 0;
	res = 1;
	n = stacks->stack_a_counter;
	m = stacks->stack_b_counter;
	while (j < n)
	{
		if (stacks->stack_a[2][j] > 0
		&& stacks->stack_a[2][j + 1] < 0)
		{
			swap_a(stacks, j);
			res = 0;
		}
		if (stacks->stack_a[2][j] == 0)
		{
			find_position_b(stacks, j);
//			push_b(stacks, j);
/*
			stacks->stack_b_pointer += find_real_moves_b(stacks, j);
			if (stacks->stack_b_pointer < 0)
				stacks->stack_b_pointer += m;
			else if (stacks->stack_b_pointer > m - 1)
				stacks->stack_b_pointer -= m;
//			stacks->b_counter++;
*/
			pull_a(stacks, j);
			n = stacks->stack_a_counter;
			print(stacks);
		}
		else
			j++;
	}
	return (res);
}

int	swap_a(t_stacks *stacks, int i)
{
	int	j;
	int	swap;

	j = (i + 1) % stacks->stack_a_counter;
	swap = stacks->stack_a[0][i];
	stacks->stack_a[0][i] = stacks->stack_a[0][j];
	stacks->stack_a[0][j] = swap;
	swap = stacks->stack_a[1][i];
	stacks->stack_a[1][i] = stacks->stack_a[1][j];
	stacks->stack_a[1][j] = swap;
	swap = stacks->stack_a[2][i];
	stacks->stack_a[2][i] = stacks->stack_a[2][j] + 1;
	stacks->stack_a[2][j] = swap - 1;
	return (0);
}

int	swap_b(t_stacks *stacks, int i)
{
	int	j;
	int	swap;

	if (stacks->stack_b_counter < 2)
		return (0);
	j = (i + 1) % stacks->stack_b_counter;
	swap = stacks->stack_b[0][i];
	stacks->stack_b[0][i] = stacks->stack_b[0][j];
	stacks->stack_b[0][j] = swap;
	swap = stacks->stack_b[1][i];
	stacks->stack_b[1][i] = stacks->stack_b[1][j];
	stacks->stack_b[1][j] = swap;
	return (0);
}
