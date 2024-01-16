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

int	input_data(t_stacks *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	(void) argv;
	if (!make_array(&stacks->stack_a, 3, argc - 1)
		|| !make_array(&stacks->stack_b, 2, argc - 1))
		return (1);
	stacks->stack_a_counter = argc - 1;
	stacks->stack_a_pointer = -1;
	while (i < argc)
	{
		if (ft_atoi(argv[i], stacks))
			return (1);
		i++;
	}
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
		if (str[i] < '0' || str[i] > '9')
			return (1);
		digits = digits * 10;
		digits = digits + str[i] - '0';
		i++;
	}
	(stacks->stack_a_pointer)++;
	stacks->stack_a[0][stacks->stack_a_pointer] = sign * digits;
	return (0);
}
