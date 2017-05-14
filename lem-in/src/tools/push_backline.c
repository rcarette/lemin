/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_backline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:34:18 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 16:40:05 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/data.h"

static t_line		*creat_new_elem(char *value, int size_value)
{
	t_line		*new_elem;

	new_elem = NULL;

	if (!(new_elem = (t_line *)malloc(sizeof(t_line))))
		exit(EXIT_FAILURE);
	new_elem->line = ft_strdup(value);
	new_elem->size_line = size_value;
	new_elem->value = -1;
	new_elem->end_room = 0;
	new_elem->start_room = 0;
	new_elem->next = NULL;
	return (new_elem);
}

void				push_backline(t_line **line, char *value, \
															int size_value)
{
	t_line		*temp_line;
	t_line		*new_elem;

	temp_line = *line;
	if (*line == NULL)
		*line = creat_new_elem(value, size_value);
	else
	{
		new_elem = creat_new_elem(value, size_value);
		while (temp_line->next)
			temp_line = temp_line->next;
		temp_line->next = new_elem;
	}
}

void				ft_clearline(t_line **line)
{
	t_line		*delete;

	while (*line)
	{
		delete = *line;
		*line = (*line)->next;
		free(delete->line);
		free(delete);
	}
}
