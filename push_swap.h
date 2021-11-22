/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:11:58 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/16 14:24:29 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# define SA	11
# define SB 12
# define SS 13
# define PB 21
# define PA 22
# define RA 31
# define RB 32
# define RR 33
# define RRA 41
# define RRB 42
# define RRR 43

# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <stdio.h>

typedef struct s_ps_list
{
	int					number;
	int					index;
	int					index_list;
	struct s_ps_list	*next;
}	t_ps_list;

typedef struct s_data
{
	int			*table;
	int			*index_table;
	int			size;
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
}	t_data;

void		print_table(int *table, int size);
int			free_error(int **table);
size_t		count_digits(int number);
void		free_arg_table(char **arg_table);
int			parse_arguments(int **table, int argc, char *argv[]);
int			create_list(t_data *data);
int			table_to_index(t_data *data);
void		print_list(t_ps_list *list);
void		test_print(t_data *data);
void		execute_operations(t_data *data, int code);
t_ps_list	*last_list_item(t_ps_list *node);
t_ps_list	*before_last_item(t_ps_list *node, int size);
int			size_list(t_ps_list *list);
void		swap_nodes(t_ps_list **stack);
void		rotate_stack(t_ps_list **stack);
void		reverse_rotate_stack(t_ps_list **stack);
void		push_stack(t_ps_list **from_stack, t_ps_list **to_stack);
void		test_operations(t_data *data);
void		sort_list(t_data *data);
void		algo_3(t_data *data);
void		algo_4(t_data *data);
void		algo_5(t_data *data);
int			already_sorted(t_ps_list *list, int size);
void		big_sort(t_data *data);
int			find_min(t_ps_list *stack);
int			find_index(t_ps_list *stack, int nr);
int			find_max(t_ps_list *stack);
int			find_max_bits(int nr);
int			reverse_sorted(t_ps_list *list, int size);
void		free_all(t_data *data);
int			valid_number(char *number);

#endif