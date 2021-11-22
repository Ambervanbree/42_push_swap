/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:00:16 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/22 12:08:07 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_all(t_data *data)
{
	t_ps_list	*temp;

	if (data->table)
	{
		free(data->table);
		data->table = 0;
	}
	if (data->index_table)
	{
		free(data->index_table);
		data->index_table = 0;
	}
	while (data->stack_a)
	{
		temp = data->stack_a;
		data->stack_a = data->stack_a->next;
		free(temp);
		temp = 0;
	}
}

int	only_one_argument(char *string)
{
	if (valid_number(string))
		return (0);
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2 && !(in_set(' ', argv[1])))
		return (only_one_argument(argv[1]));
	data.table = 0;
	data.size = parse_arguments(&data.table, argc, argv);
	if (data.size == 0)
		return (1);
	if (table_to_index(&data) == 0 || create_list(&data) == 0)
	{
		free_all(&data);
		return (1);
	}
	sort_list(&data);
	free_all(&data);
	return (0);
}
