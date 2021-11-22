/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:21:54 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/16 15:27:34 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	execute_swap(t_data *data, int code)
{
	if (code == 11)
	{
		swap_nodes(&data->stack_a);
		ft_printf("sa\n");
	}
	if (code == 12)
	{
		swap_nodes(&data->stack_b);
		ft_printf("sb\n");
	}
	if (code == 13)
	{
		swap_nodes(&data->stack_a);
		swap_nodes(&data->stack_b);
		ft_printf("ss\n");
	}
}

void	execute_push(t_data *data, int code)
{
	if (code == 21)
	{
		push_stack(&data->stack_a, &data->stack_b);
		ft_printf("pb\n");
	}
	if (code == 22)
	{
		push_stack(&data->stack_b, &data->stack_a);
		ft_printf("pa\n");
	}
}

void	execute_rotate(t_data *data, int code)
{
	if (code == 31)
	{
		rotate_stack(&data->stack_a);
		ft_printf("ra\n");
	}
	if (code == 32)
	{
		rotate_stack(&data->stack_b);
		ft_printf("rb\n");
	}
	if (code == 33)
	{
		rotate_stack(&data->stack_a);
		rotate_stack(&data->stack_b);
		ft_printf("rr\n");
	}
}

void	execute_reverse_rotate(t_data *data, int code)
{
	if (code == 41)
	{
		reverse_rotate_stack(&data->stack_a);
		ft_printf("rra\n");
	}
	if (code == 42)
	{
		reverse_rotate_stack(&data->stack_b);
		ft_printf("rrb\n");
	}
	if (code == 43)
	{
		reverse_rotate_stack(&data->stack_a);
		reverse_rotate_stack(&data->stack_b);
		ft_printf("rrr\n");
	}
}

void	execute_operations(t_data *data, int code)
{
	if (code > 10 && code < 20)
		execute_swap(data, code);
	if (code > 20 && code < 30)
		execute_push(data, code);
	if (code > 30 && code < 40)
		execute_rotate(data, code);
	if (code > 40 && code < 50)
		execute_reverse_rotate(data, code);
}
