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
	int	rotates;

	n = 0;
	while (n < stacks->chunks)
	{
		rotates = find_ra(stacks, n);
		if (rotates == -1)
			n++;
		else if (rotates <= stacks->stack_a_counter / 2)
		{
			ra(stacks, rotates);
			push_b(stacks);
		}
		else
		{
			rra(stacks, stacks->stack_a_counter - rotates);
			push_b(stacks);
		}
	}
	return (0);
}

int	scan_b(t_stacks *stacks)
{
	int	n;
	int	rotates;

	n = stacks->numbers - 1;
	while (n >= 0)
	{
		rotates = find_rb(stacks, n);
		if (rotates == -1)
			n--;
		else if (rotates <= stacks->stack_b_counter / 2)
		{
			rb(stacks, rotates);
			push_a(stacks);
		}
		else
		{
			rrb(stacks, stacks->stack_b_counter - rotates);
			push_a(stacks);
		}
	}
	return (0);
}
