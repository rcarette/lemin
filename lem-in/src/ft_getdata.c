/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:58:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 19:10:01 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

int					check_ant(char *ant, t_lemin *lemin)
{
	long long	data;

	if (ft_strlen(ant) > 10)
		return (-1);
	data = ft_atoi(ant);
	if (data > MAX_INT || data <= 0)
		return (-1);
	lemin->nbr_ant = data;
	return (1);
}

int					check_all_room_list(char *room_name, t_lemin *lemin)
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

int							ft_check_rooms(char *str, t_lemin *lemin)
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

int							ft_check_all_connect(char **board, t_lemin *lemin)
{
	t_connect		*connect;

	connect = lemin->connect;
	if (connect == NULL)
		return (1);
	while (connect)
	{
		if (ft_strcmp(connect->data_1, board[0]) == 0 \
								&& ft_strcmp(connect->data_2, board[1]) == 0)
			return (0);
		connect = connect->next;
	}
	return (1);
}

int							ft_check_connect(char *str, t_lemin *lemin)
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

int							ft_check_command(char *str)
{
	if (transform_string_lower(str, "##start"))
		return (START);
	else if (transform_string_lower(str, "##end"))
		return (END);
	else
		return (COMMENTAIRE);
}

static enum s_mod_value		parsing(char *str, t_lemin *lemin)
{
	if (*str == '#')
		return (ft_check_command(str));
	else if (ft_count_words(str) == 1 && lemin->nbr_ant == -1 && is_digit(str))
	{
		if (check_ant(str, lemin))
			return (NBR_FOURMI);
	}
	else if (ft_count_words(str) == 3)
	{
		if (ft_check_rooms(str, lemin))
			return (ROOM);
	}
	else if (ft_count_words(str) == 1 && ft_strchr(str, '-'))
	{
		if (ft_check_connect(str, lemin))
			return (CONNECT);
	}
	return (INVALID);
}

void						ft_getdata(t_lemin *lemin)
{
	char				*str;
	char				*str_t;
	enum s_mod_value	mod;

	str = NULL;
	str_t = NULL;
	while (get_next_line(0, &str))
	{
		if (!ft_strlen(str))
			return (free(str));
		strjoin_noleaks(&lemin->copy_original, str);
		strjoin_noleaks(&lemin->copy_original, "\n");
		str_t = ft_strtrim(str);
		if (!ft_strlen(str_t))
		{
			free(str);
			return (free(str_t));
		}
		ft_memdel((void *)&str);
		str = NULL;
		if ((mod = parsing(str_t, lemin) == INVALID))
			return (free(str_t));
		push_backline(&lemin->line_copy, str_t, ft_strlen(str_t), mod);
		ft_memdel((void *)&str_t);
	}
}
