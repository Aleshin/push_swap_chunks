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

int	init_array(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < N)
	{
		stacks->stack_temp[i] = stacks->stack_a[i][0];
		stacks->stack_b[i][1] = -1;
		stacks->stack_b[i][0] = 0;
		i++;
	}
	return (0);
}

int	bubble_sort(t_stacks *stacks)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N - 1)
		{
			if (stacks->stack_temp[j] > stacks->stack_temp[j + 1])
			{
				swap = stacks->stack_temp[j];
				stacks->stack_temp[j] = stacks->stack_temp[j + 1];
				stacks->stack_temp[j + 1] = swap;
			}
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

	i = 0;
	while (i < N)
	{
		j = 0;
		while (stacks->stack_a[i][0] != stacks->stack_temp[j])
			j++;
		stacks->stack_a[i][1] = j;
		if ((i <= j && j - i < N / 2) || (i >= j && i - j < N / 2))
			stacks->stack_a[i][2] = j - i;
		else if (i < j)
			stacks->stack_a[i][2] = -i - N + j;
		else
			stacks->stack_a[i][2] = N - i + j;
		i++;
	}
	return (0);
}

int	print(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a_counter)
		printf("%d,\t", stacks->stack_a[i++][0]);
	printf("\n");
	i = 0;
	while (i < stacks->stack_a_counter)
		printf("%d,\t", stacks->stack_a[i++][1] + 1);
	printf("\n");
	i = 0;
	while (i < stacks->stack_a_counter)
		printf("%d,\t", stacks->stack_a[i++][2]);
	printf("\n");
	i = 0;
	while (i < stacks->stack_b_counter)
		printf("%d,\t", stacks->stack_b[i++][0]);
	printf("\n");
	printf("\n");
	return (0);
}

int	main(void)
{
	int			j;
	int			stop_while;
	t_stacks	stacks = {.stack_a = {{7}, {100}, {3}, {20}, {9}, {2}, {5}, {11}, {4}, {90}}};

	stacks.stack_a_counter = N;
	stacks.stack_b_counter = 0;
	stacks.stack_b_pointer = -1;
	stop_while = 0;
	init_array(&stacks);
	bubble_sort(&stacks);
	find_moves(&stacks);
	print(&stacks);
	while (stacks.stack_a_counter != 0)
	{
		j = 0;
		if (stop_while == stacks.stack_a_counter)
		{
			if (stacks.stack_a[j][2] > 0)
				rotate (&stacks, -1);
			else
				rotate (&stacks, 1);
		}
		stop_while = stacks.stack_a_counter;
		while (j < stacks.stack_a_counter)
		{
			swap(&stacks, j);
			if (stacks.stack_a[j][2] == 0)
			{
				push_b(&stacks, j);
				pull_a(&stacks, j);
				print(&stacks);
			}
			j++;
			if (stacks.stack_b[stacks.stack_b_pointer][1] < stacks.stack_a[j][1] &&
				stacks.stack_b[stacks.stack_b_pointer][1] != -1)
				stacks.stack_b_pointer++;
			if (stacks.stack_b_pointer == stacks.stack_b_counter)
				stacks.stack_b_pointer = 0;
		}
	}
	return (0);
}
