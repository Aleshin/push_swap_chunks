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
	int	rotates_r;

	n = 0;
	while (n < stacks->chunks)
	{
		rotates = find_ra(stacks, n);
		rotates_r = find_rra(stacks, n);
		if (rotates == -1 || rotates_r == -1)
			n++;
		else if (rotates <= rotates_r)
		{
			ra(stacks, rotates);
			push_b(stacks);
		}
		else
		{
			rra(stacks, rotates_r);
			push_b(stacks);
		}
	}
	return (0);
}

int	scan_b(t_stacks *stacks)
{
	int	n;
	int	rotates;
	int	rotates_r;

	n = stacks->numbers - 1;
	while (n >= 0)
	{
		rotates = find_rb(stacks, n);
		rotates_r = find_rrb(stacks, n);
		if (rotates == -1 || rotates_r == -1)
			n--;
		else if (rotates <= rotates_r)
		{
			rb(stacks, rotates);
			push_a(stacks);
		}
		else
		{
			rrb(stacks, rotates_r);
			push_a(stacks);
		}
	}
	return (0);
}
