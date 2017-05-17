/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_graph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:28:40 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/17 04:14:44 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"

static t_ad_list	*creat_new_elem(char *room_connect)
{
	t_ad_list	*new_link;

	if (!(new_link = (t_ad_list *)malloc(sizeof(t_ad_list))))
		exit(EXIT_FAILURE);
	if (!(new_link->room_connect = ft_strdup(room_connect)))
		exit(EXIT_FAILURE);
	new_link->next = NULL;
	return (new_link);
}

static t_path	*creat_new_elem_path(char *room_connect)
{
	t_path	*new_link;

	if (!(new_link = (t_path *)malloc(sizeof(t_path))))
		exit(EXIT_FAILURE);
	if (!(new_link->name_room = ft_strdup(room_connect)))
		exit(EXIT_FAILURE);
	new_link->next = NULL;
	return (new_link);
}

static void			push_backpath(t_path **list, char *connect)
{
	t_path		*new_link;
	t_path		*temp_list;

	
	temp_list = *list;
	if (*list == NULL)
		*list = creat_new_elem_path(connect);
	else
	{
		new_link = creat_new_elem_path(connect);
		while (temp_list->next)
			temp_list = temp_list->next;
		temp_list->next = new_link;
	}
}

static void			push_backadlist(t_ad_list **list, char *connect)
{
	t_ad_list		*new_link;
	t_ad_list		*temp_list;

	
	temp_list = *list;
	if (*list == NULL)
		*list = creat_new_elem(connect);
	else
	{
		new_link = creat_new_elem(connect);
		while (temp_list->next)
			temp_list = temp_list->next;
		temp_list->next = new_link;
	}
}


int				ft_lenght_adlist(t_ad_list *list)
{
	int		size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}

static void			search_path(t_lemin *lemin)
{
	t_room		*room;
	t_ad_list	*connect;
	int			size;
	char		*name_room;
	t_path		*list;

	list = NULL;
	connect = NULL;
	room = lemin->room;
	while (room)
	{
		if (room->informs == 1)
		{
			name_room = room->board[0];
			connect = room->connect;
		}
		room = room->next;
	}
	size = ft_lenght_adlist(connect);
	while (size--)
		push_backpath(&lemin->path, name_room);
	list = lemin->path;
	while (list)
	{
		printf("%s\n", list->name_room);
		list = list->next;
	}
}

void	ft_creat_graph(t_lemin *lemin)
{
	t_room		*chamber;
	t_connect	*room_connect;
	t_ad_list	*ad_list;

	ad_list = NULL;

	chamber = lemin->room;
	room_connect = lemin->connect;
	while (chamber)
	{
		while (room_connect)
		{
			if (!ft_strcmp(chamber->board[0], room_connect->data_1))
				push_backadlist(&ad_list, room_connect->data_2);
			room_connect = room_connect->next;
		}
		room_connect = lemin->connect;
		chamber->connect = ad_list;
		ad_list = NULL;
		chamber = chamber->next;
	}
	search_path(lemin);
}
