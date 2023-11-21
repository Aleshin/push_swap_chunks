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

#include <stdio.h>
#include <stdlib.h>
#define N 10

int	copy_array(int stack_temp[N], int stack_input[N][3])
{
	int	i;

	i = 0;
	while (i < N)
	{
		stack_temp[i] = stack_input[i][0];
		i++;
	}
	return (0);
}

int	bubble_sort(int *stack_temp)
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
			if (stack_temp[j] > stack_temp[j + 1])
			{
				swap = stack_temp[j];
				stack_temp[j] = stack_temp[j + 1];
				stack_temp[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_moves(int stack_temp[N], int stack_input[N][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (stack_input[i][0] != stack_temp[j])
			j++;
		stack_input[i][1] = j;
		if ((i <= j && j - i < N / 2) || (i >= j && i - j < N / 2))
			stack_input[i][2] = j - i;
		else if (i < j)
			stack_input[i][2] = -i - N + j;
		else
			stack_input[i][2] = N - i + j;
		i++;
	}
	return (0);
}

int	push(int stack_input[N][3], int i, int *stack_counter)
{
	while(i < *stack_counter - 1)
	{
		stack_input[i][0] = stack_input[i + 1][0];
		stack_input[i][1] = stack_input[i + 1][1];
		stack_input[i][2] = stack_input[i + 1][2];
		if(stack_input[i][2] > 0) stack_input[i][2]--;
		if(stack_input[i][2] < 0) stack_input[i][2]++;
		i++;
	}
	(*stack_counter)--;
	return (0);
}

int	swap(int stack_input[N][3], int i, int *stack_counter)
{
	int	j;
	int	swap;

	if (i == *stack_counter - 1)
		j = 0;
	else
		j = i + 1;
	if (stack_input[i][2] > 0 && stack_input[j][2] < 0)
	{
		swap = stack_input[i][0];
		stack_input[i][0] = stack_input[j][0];
		stack_input[j][0] = swap;
		swap = stack_input[i][1];
		stack_input[i][1] = stack_input[j][1];
		stack_input[j][1] = swap;
		stack_input[i][2]--;
		stack_input[j][2]++;
	}
	return (0);
}

int	print(int stack_temp[N], int stack_input[N][3], int *stack_counter)
{
	int	i;

	i = 0;
	while (i < *stack_counter)
		printf("%d,\t", stack_input[i++][0]);
	printf("\n");
	i = 0;
	while (i < *stack_counter)
		printf("%d,\t", stack_input[i++][1] + 1);
	printf("\n");
	i = 0;
	while (i < *stack_counter)
		printf("%d,\t", stack_input[i++][2]);
	printf("\n");
	i = 0;
	while (i < N)
		printf("%d,\t", stack_temp[i++]);
	printf("\n");
	printf("\n");
	return (0);
}

int	main(void)
{
	int	j;
	int	stack_input[N][3] = {{1}, {100}, {3}, {20}, {9}, {2}, {5}, {11}, {4}, {90}};
	int	stack_temp[N];
	int	stack_counter;
	int	stop_while;

	stack_counter = N;
	stop_while = 0;
	copy_array(stack_temp, stack_input);
	bubble_sort(stack_temp);
	find_moves(stack_temp, stack_input);
	copy_array(stack_temp, stack_input);
	print(stack_temp, stack_input, &stack_counter);
	while (stack_counter != stop_while)
	{
		stop_while = stack_counter;
		j = 0;
		while ( j < stack_counter)
		{
			swap(stack_input, j, &stack_counter);
			if (stack_input[j][2] == 0)
			{
				stack_temp[stack_input[j][1]] = stack_input[j][0];
				push(stack_input, j, &stack_counter);
				print(stack_temp, stack_input, &stack_counter);
			}
		j++;
		}
	}
	return (0);
}
