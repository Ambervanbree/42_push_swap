/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:05:46 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/07 15:20:16 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	bubble_sort(int **table, int size)
{
	int	i;
	int	temp;
	int	swapped;

	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if ((*table)[i] > (*table)[i + 1])
			{
				temp = (*table)[i];
				(*table)[i] = (*table)[i + 1];
				(*table)[i + 1] = temp;
				swapped++;
			}
			i++;
		}
	}
}

int	fill_index_table(t_data *data, int *sorted_table)
{
	int	i;
	int	j;

	data->index_table = malloc(sizeof(int) * data->size);
	if (data->index_table == 0)
		return (0);
	i = 0;
	while (i < data->size)
	{
		j = 0;
		while (j < data->size)
		{
			if (data->table[i] == sorted_table[j])
				data->index_table[i] = j;
			j++;
		}
		i++;
	}
	return (1);
}

int	table_to_index(t_data *data)
{
	int	*sorted_table;
	int	i;

	sorted_table = malloc(sizeof(int) * data->size);
	if (sorted_table == 0)
		return (0);
	i = 0;
	while (i < data->size)
	{
		sorted_table[i] = (data->table)[i];
		i++;
	}
	bubble_sort(&sorted_table, data->size);
	if (fill_index_table(data, sorted_table) == 0)
	{	
		free(sorted_table);
		sorted_table = 0;
		return (0);
	}
	free(sorted_table);
	sorted_table = 0;
	return (1);
}
