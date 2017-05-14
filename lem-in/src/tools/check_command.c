/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:51:46 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 18:52:14 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

int				check_command(t_lemin *lemin)
{
	t_line		*temp_line;

	temp_line = lemin->line_copy;
	while (temp_line)
	{
		if (temp_line->value == START)
			++lemin->start;
		if (temp_line->value == END)
			++lemin->end;
		temp_line = temp_line->next;
	}
	if (lemin->start == 1 && lemin->end == 1)
		return (1);
	return (0);
}
