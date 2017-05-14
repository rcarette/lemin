/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dupliq_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:49:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 18:51:11 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

static void		stock_rooms(t_lemin *lemin)
{
	t_line		*temp_line;
	char		*copy;
	int			ite;
	char		**board;

	ite = -1;
	temp_line = lemin->line_copy;
	while (temp_line)
	{
		ite = -1;
		if (temp_line->value == ROOM)
		{
			copy = manage_string((char * )temp_line->line, \
												ft_strlen(temp_line->line));
			board = ft_strsplit(copy, 4);
			push_backroom(&lemin->room, temp_line->line, board);
			ft_memdel((void *)&copy);
		}
		temp_line = temp_line->next;
	}
}

int		check_dupliq_rooms(t_lemin *lemin)
{
	t_room		*temp_room;
	t_room		*temp_rooms;

	stock_rooms(lemin);
	temp_room = lemin->room;
	while (temp_room)
	{
		temp_rooms = temp_room->next;
		if (!temp_rooms)
			return (1);
		while (temp_rooms)
		{
			if (!strcmp(temp_room->board[0], temp_rooms->board[0]))
				return (0);
			temp_rooms = temp_rooms->next;
		}
		temp_room = temp_room->next;
	}
	return (1);
}
