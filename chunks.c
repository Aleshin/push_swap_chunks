/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:33:26 by saleshin          #+#    #+#             */
/*   Updated: 2024/03/06 16:33:44 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	scan_a(t_stacks *stacks)
{
	int	n;
	int rotates;

	n = 0;
	while (n < stacks->chunks)
	{
		rotates = find_ra(stacks, n);
		if (rotates != -1)
		{
			print_moves("ra", rotates);
			stacks->stack_a_pointer = (stacks->stack_a_pointer + rotates) % stacks->stack_a_counter;
			push_b(stacks);
        }
        else
            n++;
	}
	return (0);
}

int	find_ra(t_stacks *stacks, int chunk_no)
{
	int	rotates;
    int pos;

    rotates = 0;
	pos = stacks->stack_a_pointer;
	while (rotates < stacks->stack_a_counter)
	{
		if (stacks->stack_a[2][pos] == chunk_no)
			return (rotates);
		else
        {
			pos = (pos + 1) % stacks->stack_a_counter;
            rotates++;
        }
	}	
	return (-1);
}

int	scan_b(t_stacks *stacks)
{
	int	i;

	i = stacks->numbers - 1;
	while (i >= 0)
	{
		while (stacks->stack_b[1][stacks->stack_b_pointer] != i)
            stacks->stack_b_pointer = (stacks->stack_b_pointer +1) % stacks->stack_b_counter;
        push_a(stacks);
//			write(1, "rb\n", 3);
	i--;
    }
	return (0);
}
