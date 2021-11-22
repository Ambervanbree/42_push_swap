/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:21:58 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/10 19:10:40 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	already_sorted(t_ps_list *list, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (list->next->index != list->index + 1)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

int	reverse_sorted(t_ps_list *list, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (list->next->index != list->index - 1)
			return (0);
		list = list->next;
		i++;
	}
	return (1);
}

void	sort_list(t_data *data)
{
	if (already_sorted(data->stack_a, data->size))
		return ;
	else if (data->size == 2)
		execute_operations(data, 11);
	else if (data->size == 3)
		algo_3(data);
	else if (data->size == 4)
		algo_4(data);
	else if (data->size == 5)
		algo_5(data);
	else
		big_sort(data);
}
