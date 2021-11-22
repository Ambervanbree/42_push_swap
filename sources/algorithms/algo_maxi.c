/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_maxi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:17:30 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/16 18:58:53 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	action_necessary(t_ps_list *list, int index, int size)
{
	int	i;
	int	uneven;

	i = 0;
	uneven = 0;
	while (i < size)
	{
		if ((list->index >> index & 1) == 1)
			uneven++;
		i++;
		list = list->next;
	}
	if (uneven == 0)
		return (0);
	else
		return (1);
}

int	push_back_necessary(t_ps_list *list, int i)
{
	int	uneven;

	uneven = 0;
	while (list)
	{
		if ((list->index >> i & 1) == 1)
			uneven++;
		list = list->next;
	}
	if (uneven == 0)
		return (0);
	else
		return (1);
}

void	push_or_rotate(t_data *data, int i)
{
	int	size;

	size = size_list(data->stack_a);
	while (size)
	{
		if (action_necessary(data->stack_a, i, size))
		{
			if ((data->stack_a->index >> i & 1) == 1)
				execute_operations(data, RA);
			else
				execute_operations(data, PB);
			size--;
		}
		else
			break ;
	}
}

void	big_sort(t_data *data)
{
	int	i;
	int	max;
	int	max_bits;

	max = find_max(data->stack_a);
	max_bits = find_max_bits(max);
	i = 0;
	while (i < max_bits)
	{
		push_or_rotate(data, i);
		while (data->stack_b && push_back_necessary(data->stack_b, i + 1))
			execute_operations(data, PA);
		i++;
	}
	while (data->stack_b)
		execute_operations(data, PA);
}
