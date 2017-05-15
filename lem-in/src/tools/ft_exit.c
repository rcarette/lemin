/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:35:33 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 19:21:06 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

static void		clear_line(t_lemin *lemin)
{
	t_line		*delete;

	if (!lemin->line_copy)
		return ;
	delete = lemin->line_copy;
	while (lemin->line_copy)
	{
		delete = lemin->line_copy;
		lemin->line_copy = lemin->line_copy->next;
		free(delete->line);
		free(delete);
	}
}

static void		clear_rooms(t_lemin *lemin)
{
	t_room		*delete;

	if (!lemin->room)
		return ;
	delete = lemin->room;
	while (lemin->room)
	{
		delete = lemin->room;
		lemin->room = lemin->room->next;
		free(delete->room);
		clear_tab(delete->board);
		free(delete);
	}
}

static void		clear_connect(t_lemin *lemin)
{
	t_connect	*delete;

	if (!lemin->connect)
		return ;
	delete = lemin->connect;
	while (lemin->connect)
	{
		delete = lemin->connect;
		lemin->connect = lemin->connect->next;
		free(delete->data_1);
		free(delete->data_2);
		free(delete);
	}
}

void	ft_exit(t_lemin *lemin)
{
	free(lemin->copy_original);
	clear_line(lemin);
	clear_rooms(lemin);
	clear_connect(lemin);
	write(1, "Error\n", 6);
	exit(0);
}
