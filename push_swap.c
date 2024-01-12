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
	int	n;

	i = 0;
	n = stacks->stack_a_counter;
	while (i < n)
	{
		j = 0;
		while (stacks->stack_a[0][i] != stacks->stack_temp[j])
			j++;
		stacks->stack_a[1][i] = j;
		if ((i <= j && i - j < n / 2) || (j >= i && j - i < n / 2))
			stacks->stack_a[2][i] = i - j;
		else if (i < j)
			stacks->stack_a[2][i] = -j - n + i;
		else
			stacks->stack_a[2][i] = n - j + i;
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
	while (i < N) //stacks->stack_b_counter)
		if (stacks->stack_b[i++][1] == -1)
			printf("\t");
			else
				printf("%d,\t", stacks->stack_b[i-1][0]);
	printf("\n");
	i = 0;
	while (i < N)
		printf("%d,\t", stacks->stack_b[i++][1]);
	printf("\n\n");
	return (0);
}

int	init(t_stacks *stacks)
{
	int	i;

	i = 0;
//	stacks->stack_a_counter = N;
	stacks->stack_a_pointer = 0;
	stacks->stack_b_counter = 0;
	stacks->stack_b_pointer = -1;
	while (i < stacks->stack_a_counter)
	{
		stacks->stack_temp[i] = stacks->stack_a[0][i];
		stacks->stack_b[i][1] = -1;
		stacks->stack_b[i][0] = 0;
		i++;
	}
	bubble_sort(stacks);
	find_moves(stacks);
	print(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	t_stacks	stacks; // = {.stack_a = {{7}, {100}, {3}, {20},
//	{9}, {2}, {5}, {11}, {4}, {90}}};

	i = 1;
	if (argc > 1)
	{
		if (!make_array(&stacks, 3, argc - 1))
				return (write(1,"error\n",6));
		stacks.stack_a_counter = argc - 1;
		stacks.stack_a_pointer = 0;
		while (i < argc)
		{
			if (ft_atoi(argv[i], &stacks))
				return (write(1,"error\n",6));
			printf("%d\n", stacks.stack_a[0][i]);
			i++;
		}
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
