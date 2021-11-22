/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:40:09 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/22 12:14:50 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	valid_number(char *number)
{
	if (!(in_set(number[0], "-0123456789")))
		return (0);
	if (ft_atoi(number) == 0 && !(ft_strncmp("0", number, 1) == 0))
		return (0);
	if (ft_atoi(number) == -1 && !(ft_strncmp("-1", number, 2) == 0))
		return (0);
	if (ft_strlen(number) != count_digits(ft_atoi(number)))
		return (0);
	return (1);
}

static int	double_number(int *table, int number, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (table[i] == number)
			return (1);
		i++;
	}
	return (0);
}

static int	split_argument(int **table, char *string, int *size)
{
	char	**arg_table;
	int		i;

	if (ft_strncmp(string, " ", ft_strlen(string)) == 0)
		return (0);
	arg_table = ft_split(string, ' ');
	*size = 0;
	while (arg_table[*size] != NULL)
		(*size)++;
	*table = malloc(sizeof(int) * (*size));
	if (*table == 0)
		return (0);
	i = 0;
	while (arg_table[i] != 0)
	{
		if (!(valid_number(arg_table[i]))
			|| double_number(*table, ft_atoi(arg_table[i]), i))
		{
			free_arg_table(arg_table);
			return (0);
		}
		(*table)[i] = ft_atoi(arg_table[i]);
		i++;
	}
	free_arg_table(arg_table);
	return (1);
}

int	parse_arguments(int **table, int argc, char *argv[])
{
	int	i;
	int	size;

	if (argc == 2)
	{
		if (split_argument(table, argv[1], &size) == 0)
			return (free_error(table));
	}
	else
	{
		size = argc - 1;
		*table = malloc(sizeof(int) * size);
		if (*table == 0)
			return (0);
		i = 1;
		while (i < argc)
		{
			if (!(valid_number(argv[i]))
				|| double_number(*table, ft_atoi(argv[i]), i - 1))
				return (free_error(table));
			(*table)[i - 1] = ft_atoi(argv[i]);
			i++;
		}
	}
	return (size);
}
