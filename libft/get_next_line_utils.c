/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:27:16 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/25 17:23:47 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	free_function(char **string)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
}

int	index_rest(char *string)
{
	size_t		index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == '\n')
			return (index + 1);
		index++;
	}
	return (-1);
}
