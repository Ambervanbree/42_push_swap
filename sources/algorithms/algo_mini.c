/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:32:59 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/16 14:37:58 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	algo_3(t_data *data)
{
	if (data->stack_a->index < data->stack_a->next->index
		&& data->stack_a->index < data->stack_a->next->next->index)
	{
		execute_operations(data, SA);
		execute_operations(data, RA);
	}
	else if (data->stack_a->index > data->stack_a->next->index
		&& data->stack_a->index > data->stack_a->next->next->index)
	{
		if (data->stack_a->next->index == data->stack_a->index - 1)
		{
			execute_operations(data, RA);
			execute_operations(data, SA);
		}
		else
			execute_operations(data, RA);
	}
	else
	{
		if (data->stack_a->next->index == data->stack_a->index - 1)
			execute_operations(data, SA);
		else
			execute_operations(data, RRA);
	}
}

void	algo_4(t_data *data)
{
	int	min;
	int	index_min;

	min = find_min(data->stack_a);
	index_min = find_index(data->stack_a, min);
	if (index_min == 1)
		execute_operations(data, SA);
	if (index_min > 1)
		while (index_min++ != 4)
			execute_operations(data, RRA);
	if (already_sorted(data->stack_a, data->size - 1))
		return ;
	execute_operations(data, PB);
	algo_3(data);
	execute_operations(data, PA);
}

void	algo_5(t_data *data)
{
	int	min;
	int	index_min;

	min = find_min(data->stack_a);
	index_min = find_index(data->stack_a, min);
	if (index_min == 1 || index_min == 2)
		while (index_min-- != 0)
			execute_operations(data, RA);
	else if (index_min > 2)
		while (index_min++ != 5)
			execute_operations(data, RRA);
	if (already_sorted(data->stack_a, data->size))
		return ;
	execute_operations(data, PB);
	algo_4(data);
	execute_operations(data, PA);
}
