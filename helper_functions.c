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

int	make_array(t_stacks *stacks, int i, int j)
{
	int	*ptr;
	int	n;

	n = 0;
	stacks->stack_a = malloc(i * sizeof(int*) + i * j * sizeof(int));
	if (!stacks->stack_a)
		return (0);
	ptr = (int*)(stacks->stack_a + i);
	while (n < i)
	{
		stacks->stack_a[n] = ptr + j * n;
		n++;
	}
	return (1);
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
