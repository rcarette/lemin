/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:48:55 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/17 03:34:14 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

static void		init_lemin(t_lemin *lemin)
{
	lemin->copy_original = NULL;
	lemin->line_copy = NULL;
	lemin->connect = NULL;
	lemin->room = NULL;
	lemin->path = NULL;
	lemin->nbr_ant = -1;
	lemin->nbr_s = 0;
	lemin->nbr_e = 0;
}

static int		check_connect_if_exist(t_lemin *lemin)
{
	t_room		*room;
	t_connect	*connect;
	char		i;

	room = lemin->room;
	connect = lemin->connect;
	while (connect)
	{
		i = 0;
		while (room)
		{
			if (!ft_strcmp(connect->data_1, room->board[0]))
				++i;
			else if (!ft_strcmp(connect->data_2, room->board[0]))
				++i;
			if (i == 2)
				break ;
			room = room->next;
		}
		room = lemin->room;
		if (i != 2)
			return (0);
		connect = connect->next;
	}
	return (1);
}

void			search_start_end_room(t_lemin *lemin, char *model, \
												char *value, int choice)
{
	t_room		*room;
	t_room		*room_prev;

	room = lemin->room;
	while (room)
	{
		room_prev = room;
		if (!ft_strncmp(room->board[0], value, ft_strlen(room->board[0])) \
									&& ft_strcmp(model, room_prev->board[0]))
			room->informs = choice;
		room = room->next;
	}
}

static int		check_after_start_end(t_lemin *lemin)
{
	t_line		*line;
	int			i;
	t_room		*room;

	i = 0;
	line = lemin->line_copy;
	room = lemin->room;
	while (line)
	{
		if (line->value == START || line->value == END)
			if (line->next != NULL && line->next->value == ROOM)
			{
				if (line->value == START)
				{
					search_start_end_room(lemin, "##start", line->next->line, 1);
					line->start = 1;
				}
				else
				{
					search_start_end_room(lemin, "##end", line->next->line, 2);
					line->end = 2;
				}
				++i;
			}
		if (i == 2)
			return (1);
		line = line->next;
	}
	return (0);
}

static void		ft_checking(t_lemin *lemin)
{
	(!lemin->line_copy) ? ft_exit(lemin) : 0;
	(!lemin->nbr_ant) ? ft_exit(lemin) : 0;
	(!lemin->room) ? ft_exit(lemin) : 0;
	(!lemin->connect) ? ft_exit(lemin) : 0;
	(lemin->nbr_s != 1) ? ft_exit(lemin) : 0;
	(lemin->nbr_e != 1) ? ft_exit(lemin) : 0;
	if (!check_connect_if_exist(lemin))
		ft_exit(lemin);
	else if (!check_after_start_end(lemin))
		ft_exit(lemin);
}

int				main(void)
{
	t_lemin		lemin;
	//t_room		*chamber;

	init_lemin(&lemin);
	ft_getdata(&lemin);
	ft_checking(&lemin);
	ft_creat_graph(&lemin);

	/*chamber = lemin.room;
	t_ad_list	*li;

	while (chamber)
	{
		printf("Room : %s\n", chamber->room);
		li = chamber->connect;
		while (li)
		{

			printf("Connect : %s\n", li->room_connect);
			li = li->next;
		}
		chamber = chamber->next;
	}
	return (0);*/
}
