/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:20:44 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/10 10:23:15 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_ps_list	*new_item(t_data data, int i)
{
	t_ps_list	*node;

	node = malloc(sizeof(t_ps_list));
	if (!(node))
		return (0);
	node->number = data.table[i];
	node->index = data.index_table[i];
	node->index_list = 0;
	node->next = NULL;
	return (node);
}

int	add_item_back(t_ps_list **list, t_ps_list *new)
{
	t_ps_list	*last;

	new->index_list = size_list(*list);
	if (*list == 0)
		*list = new;
	else
	{
		last = last_list_item(*list);
		last->next = new;
	}
	return (1);
}

int	create_list(t_data *data)
{
	int			i;
	t_ps_list	*new;

	data->stack_a = NULL;
	data->stack_b = NULL;
	i = 0;
	while (i < data->size)
	{
		new = new_item(*data, i);
		if (new == 0)
			return (0);
		add_item_back(&data->stack_a, new);
		i++;
	}
	return (1);
}
