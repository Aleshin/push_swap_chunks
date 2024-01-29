/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:00:28 by saleshin          #+#    #+#             */
/*   Updated: 2023/08/14 18:34:19 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	make_array(int ***array, int i, int j)
{
	int	*ptr;
	int	n;

	n = 0;
	*array = malloc (i * sizeof(int *) + i * j * sizeof(int));
	if (!*array)
		return (0);
	ptr = (int *)(*array + i);
	while (n < i)
	{
		(*array)[n] = ptr + j * n;
		n++;
	}
	return (1);
}

int	check_number(char c, int n, int sign)
{
	if (c < '0' || c > '9')
		return (1);
	if ((INT_MAX - n * 10) < c - '0' && sign > 0)
		return (1);
	if ((INT_MIN + n * 10) > -(int)(c - '0') && sign < 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str, t_stacks *stacks)
{
	int	i;
	int	sign;
	int	digits;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	digits = 0;
	while (str[i] != '\0')
	{
		if (check_number(str[i], digits, sign))
			return (1);
		digits = digits * 10 + str[i] - '0';
		i++;
	}
	(stacks->stack_a_pointer)++;
	stacks->stack_a[0][stacks->stack_a_pointer] = sign * digits;
	return (0);
}

int	input_data(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	(void) argv;
	if (!make_array(&stacks->stack_a, 3, argc - 1))
		return (1);
	else if (!make_array(&stacks->stack_b, 2, argc - 1))
	{
		free(stacks->stack_a);
		return (1);
	}
	stacks->stack_a_counter = argc - 1;
	stacks->stack_a_pointer = -1;
	while (i < argc)
	{
		if (ft_atoi(argv[i], stacks))
		{
			free(stacks->stack_a);
			free(stacks->stack_b);
			return (1);
		}
		i++;
	}
	if (init(stacks))
		return (1);
	return (0);
}

int	find_moves_b(t_stacks *stacks, int a_pointer)
{
	int	i;
	int	j;
	int	n;
	int	m;

	j = stacks->stack_a[1][a_pointer];
	i = stacks->stack_b_pointer;
	n = stacks->b_counter;
	if ((i <= j && j - i <= n / 2) || (i >= j && i - j <= n / 2))
		m = j - i;
	else if (i < j)
		m = -i - n + j;
	else
		m = n - i + j;
	return (m);
}

int	find_real_moves_b(t_stacks *stacks, int a_pointer)
{
	int	i;
	int	m;
	int	sign;

	i = 0;
	sign = 1;
	m = find_moves_b(stacks, a_pointer);
	if (m < 0)
		sign = -1;
//	while ()
	return (m);
}
