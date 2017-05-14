/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_room_after_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:55:45 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 18:56:47 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

int		if_room_after_command(t_lemin *lemin, enum s_mod_value mod)
{
	t_line		*temp_line;

	temp_line = lemin->line_copy;
	while (temp_line)
	{
		if (temp_line->value == mod)
		{
			if (temp_line->next == NULL)
				return (0);
			else if (temp_line->next->value == ROOM)
			{
					if (mod == END)
						temp_line->end_room = 1;
					else if (mod == START)
						temp_line->start_room = 1;
				return (1);
			}
		}
		temp_line = temp_line->next;
	}
	return (0);
}
