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

int	bubble_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < stacks->stack_a_counter)
	{
		j = 0;
		while (j < stacks->stack_a_counter - 1)
		{
			if (stacks->stack_b[0][j] > stacks->stack_b[0][j + 1])
			{
				swap = stacks->stack_b[0][j];
				stacks->stack_b[0][j] = stacks->stack_b[0][j + 1];
				stacks->stack_b[0][j + 1] = swap;
			}
			if (stacks->stack_b[0][j] == stacks->stack_b[0][j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	find_moves(t_stacks *stacks)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = stacks->stack_a_counter;
	while (i < n)
	{
		j = 0;
		while (stacks->stack_a[0][i] != stacks->stack_b[0][j])
			j++;
		stacks->stack_a[1][i] = j;
		if ((i <= j && j - i <= n / 2) || (i >= j && i - j <= n / 2))
			stacks->stack_a[2][i] = j - i;
		else if (i < j)
			stacks->stack_a[2][i] = -i - n + j;
		else
			stacks->stack_a[2][i] = n - i + j;
		i++;
	}
	return (0);
}

int	find_chunks(t_stacks *stacks)
{
	int	i;
	int	chunk_no;

	i = 0;
	while (i < stacks->numbers)
	{
		chunk_no = stacks->stack_a[1][i] / stacks->chunk_size;
		if (chunk_no >= stacks->chunks)
			chunk_no = stacks->chunks -1;
		stacks->stack_a[2][i] = chunk_no;
		i++;
	}
	return (0);
}

int	init(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->stack_a_pointer = 0;
	stacks->stack_b_counter = 0;
	stacks->stack_b_pointer = 0;
	stacks->numbers = stacks->stack_a_counter;
	if (stacks->numbers <= 100)
		stacks->chunks = 5;
	else if (stacks->numbers <= 500)
		stacks->chunks = 14;
	else
		stacks->chunks = stacks->numbers / 50;
	stacks->chunk_size = stacks->stack_a_counter / stacks->chunks;
	while (i < stacks->stack_a_counter)
	{
		stacks->stack_b[1][i] = -1;
		stacks->stack_b[0][i] = stacks->stack_a[0][i];
		i++;
	}
	if (bubble_sort(stacks))
		return (1);
	find_moves(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	stacks;

	i = 1;
	if (argc > 1)
	{
		if (input_data(&stacks, argc, argv))
			return (write(2, "Error\n", 6));
	}
	else
		return (0);
	if (special_cases(&stacks, argc - 1))
	{
		free(stacks.stack_a);
		free(stacks.stack_b);
		return (0);
	}
	scan_a(&stacks);
	scan_b(&stacks);
	free(stacks.stack_a);
	free(stacks.stack_b);
	return (0);
}
