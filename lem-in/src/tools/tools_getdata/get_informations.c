/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:43:16 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/16 14:50:03 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/main.h"

int		ft_check_command(char *str, t_lemin *lemin)
{
	if (transform_string_lower(str, "##start"))
	{
		++lemin->nbr_s;
		return (START);
	}
	else if (transform_string_lower(str, "##end"))
	{
		++lemin->nbr_e;
		return (END);
	}
	else
		return (COMMENTAIRE);
}

int		ft_check_connect(char *str, t_lemin *lemin)
{
	char	**board;

	if (!ft_strchr(str, '-'))
		return (0);
	else if (ft_strlen_n(str, '-') > 1)
		return (0);
	board = ft_strsplit(str, '-');
	if (ft_strlen_tab(board) != 2)
		return (clear_tab(board));
	else if (!ft_strcmp(board[0], board[1]))
		return (clear_tab(board));
	if (!ft_check_all_connect(board, lemin))
		return (clear_tab(board));
	push_backconnect(&lemin->connect, board[0], board[1]);
	clear_tab(board);
	return (1);
}

int		ft_check_all_connect(char **board, t_lemin *lemin)
{
	t_connect		*connect;

	connect = lemin->connect;
	if (connect == NULL)
		return (1);
	while (connect)
	{
		if (ft_strcmp(connect->data_1, board[0]) == 0 \
								&& ft_strcmp(connect->data_2, board[1]) == 0)
		{
			return (0);
		}
		connect = connect->next;
	}
	return (1);
}

int		ft_check_rooms(char *str, t_lemin *lemin)
{
	char		*copy_str;
	char		**board;
	long long	data[2];

	copy_str = delimited_string(str);
	board = ft_strsplit(copy_str, 4);
	ft_memdel((void *)&copy_str);
	if (!is_digit(board[1]))
		return (clear_tab(board));
	else if (!is_digit(board[2]))
		return (clear_tab(board));
	else if (ft_strlen(board[1]) > 10 || ft_strlen(board[2]) > 10)
		return (clear_tab(board));
	data[0] = ft_atoi(board[0]);
	data[1] = ft_atoi(board[1]);
	if (data[0] < 0 || data[0] > MAX_INT)
		return (clear_tab(board));
	else if (data[1] < 0 || data[1] > MAX_INT)
		return (clear_tab(board));
	else if (!check_all_room_list(board[0], lemin))
		return (clear_tab(board));
	push_backroom(&lemin->room, str, board);
	return (1);
}

int		check_all_room_list(char *room_name, t_lemin *lemin)
{
	t_room		*room;

	room = lemin->room;
	if (room == NULL)
		return (1);
	while (room)
	{
		if (!ft_strncmp(room_name, room->room, ft_strlen(room_name)))
			return (0);
		room = room->next;
	}
	return (1);
}
