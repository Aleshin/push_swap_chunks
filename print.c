/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:23:34 by saleshin          #+#    #+#             */
/*   Updated: 2024/03/07 15:23:40 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	print_moves(char *str, int c)
{
	int	i;

	i = 0;
	while (i++ < c)
	{
		write (1, str, ft_strlen(str));
		write (1, "\n", 1);
	}
	return (0);
}
