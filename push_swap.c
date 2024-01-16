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

int	print(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a_counter)
		printf("%d,\t", stacks->stack_a[0][i++]);
	printf("\n");
	i = 0;
	while (i < stacks->stack_a_counter)
		printf("%d,\t", stacks->stack_a[1][i++] + 1);
	printf("\n");
	i = 0;
	while (i < stacks->stack_a_counter)
		printf("%d,\t", stacks->stack_a[2][i++]);
	printf("\n");
	i = 0;
	while (i < stacks->stack_b_counter)
		if (stacks->stack_b[1][i++] == -1)
			printf("\t");
	else
		printf("%d,\t", stacks->stack_b[0][i - 1]);
	printf("\n");
	i = 0;
	while (i < stacks->stack_b_counter)
		printf("%d,\t", stacks->stack_b[1][i++] + 1);
	printf("\n\n");
	return (0);
}

int	init(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->stack_a_pointer = 0;
	stacks->stack_b_counter = stacks->stack_a_counter;
	stacks->stack_b_pointer = -1;
	while (i < stacks->stack_a_counter)
	{
		stacks->stack_b[1][i] = -1;
		stacks->stack_b[0][i] = stacks->stack_a[0][i];
		i++;
	}
	bubble_sort(stacks);
	find_moves(stacks);
	print(stacks);
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
			return (write(1, "error\n", 6));
	}
	else
		return (0);
	init(&stacks);
	while (stacks.stack_a_counter > 0)
	{
		if (swaps_pushes(&stacks) && stacks.stack_a_counter > 0)
		{
			if (stacks.stack_a[2][0] > 0)
				rotate_a (&stacks, -1);
			else
				rotate_a (&stacks, 1);
		}
		print(&stacks);
	}
	return (0);
}
