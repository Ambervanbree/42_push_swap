/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:39:17 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/16 15:30:17 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_table(int *table, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", table[i]);
		i++;
	}
}

int	free_error(int **table)
{
	if (*table)
	{
		free(*table);
		*table = 0;
	}
	ft_putstr_fd("Error\n", 2);
	return (0);
}

size_t	count_digits(int number)
{
	size_t	digits;

	digits = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number *= -1;
		digits++;
	}
	while (number > 0)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}

void	free_arg_table(char **arg_table)
{
	int	i;

	i = 0;
	if (arg_table)
	{
		while (arg_table[i] != 0)
		{
			free(arg_table[i]);
			arg_table[i] = NULL;
			i++;
		}
		free(arg_table);
		arg_table = NULL;
	}
}
