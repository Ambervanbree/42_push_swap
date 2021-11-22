/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:05:28 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/09 18:21:06 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_min(t_ps_list *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	find_index(t_ps_list *stack, int nr)
{
	int	index;

	index = 0;
	while (stack->index != nr)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

int	find_max(t_ps_list *stack)
{
	int	max;

	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_max_bits(int nr)
{
	int	i;

	i = 0;
	while ((nr >> i) != 0)
		i++;
	return (i);
}
