/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_backroom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 02:22:10 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 15:56:52 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

static t_room		*creat_new_elem(char *value, char **board)
{
	t_room		*new_elem;

	new_elem = NULL;

	if (!(new_elem = (t_room *)malloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	new_elem->room = ft_strdup(value);
	new_elem->board = board;
	new_elem->next = NULL;
	return (new_elem);
}

void				push_backroom(t_room **room, char *value, char **board)
{
	t_room		*temp_line;
	t_room		*new_elem;

	temp_line = *room;
	if (*room == NULL)
		*room = creat_new_elem(value, board);
	else
	{
		new_elem = creat_new_elem(value, board);
		while (temp_line->next)
			temp_line = temp_line->next;
		temp_line->next = new_elem;
	}
}
