/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:00:03 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/07 15:20:35 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_nodes(t_ps_list **stack)
{
	t_ps_list	*cp_first;
	t_ps_list	*cp_second;

	cp_first = *stack;
	cp_second = (*stack)->next;
	cp_first->next = cp_second->next;
	cp_second->next = cp_first;
	*stack = cp_second;
}

void	push_stack(t_ps_list **from_stack, t_ps_list **to_stack)
{
	t_ps_list	*temp;

	if (*to_stack)
	{
		temp = *from_stack;
		*from_stack = temp->next;
		temp->next = *to_stack;
		*to_stack = temp;
	}
	else
	{
		temp = *from_stack;
		*from_stack = temp->next;
		*to_stack = temp;
		(*to_stack)->next = NULL;
	}
}

void	rotate_stack(t_ps_list **stack)
{
	t_ps_list	*last;
	t_ps_list	*temp;

	last = last_list_item(*stack);
	temp = *stack;
	last->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	reverse_rotate_stack(t_ps_list **stack)
{
	t_ps_list	*last;
	t_ps_list	*new_last;
	t_ps_list	*temp;
	int			i;

	i = 0;
	last = last_list_item(*stack);
	temp = *stack;
	new_last = before_last_item(*stack, size_list(*stack));
	last->next = temp;
	new_last->next = NULL;
	*stack = last;
}
