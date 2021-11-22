/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:26:21 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/10 10:07:23 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_ps_list	*before_last_item(t_ps_list *node, int size)
{
	int	i;

	i = 0;
	if (node)
	{
		while (i < size - 2)
		{
			node = node->next;
			i++;
		}
	}
	return (node);
}

void	print_list(t_ps_list *list)
{
	while (list)
	{
		ft_printf("%d ", list->number);
		ft_printf("(%d) ", list->index);
		ft_printf("%d ", list->index_list);
		list = list->next;
	}
}

void	test_print(t_data *data)
{
	ft_printf("List a\n");
	print_list(data->stack_a);
	ft_printf("\nList b\n");
	print_list(data->stack_b);
	ft_printf("\n");
}

t_ps_list	*last_list_item(t_ps_list *node)
{
	if (node)
		while (node->next)
			node = node->next;
	return (node);
}

int	size_list(t_ps_list *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
