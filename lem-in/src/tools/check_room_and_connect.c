/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room_and_connect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:53:26 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 18:54:53 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

int			check_room_and_connect(t_lemin *lemin)
{
	t_line			*temp_line;
	unsigned long	rooms;
	unsigned long	connect;

	rooms = 0;
	connect = 0;
	temp_line = lemin->line_copy;
	while (temp_line)
	{
		if (temp_line->value == CONNECT)
			++connect;
		else if (temp_line->value == ROOM)
			++rooms;
		temp_line = temp_line->next;
	}
	if (connect && rooms)
		return (1);
	return (0);
}
