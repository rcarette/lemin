/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:58:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 02:38:41 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

/*void		ft_check_value_com(t_lemin *lemin)
{
	t_com	*temp_com;

	temp_com = lemin->coment;
	while (temp_com)
	{
		if (!ft_strcmp(temp_com->value, "##start"))
		{
			temp_com->valid = 1;
			++lemin->start;
		}
		else if (!ft_strcmp(temp_com->value, "##end"))
		{
			temp_com->valid = 2;
			++lemin->end;
		}
		else
			temp_com->valid = -1;
		temp_com = temp_com->next;
	}
	if (!lemin->start || !lemin->end)
		exit(0);
}*/

int			count_tab(char **board)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (board[++i])
		++size;
	return (size);
}


void		ft_getdata_room(t_lemin *lemin)
{
	t_line		*temp_line;
	char		**board;

	temp_line = lemin->line_copy;
	while (temp_line)
	{
		board = ft_strsplit(temp_line->line, ' ');
		if (board == NULL || count_tab(board) != 3)
			clear_tab(board);
		else
		{
			if (ft_strlen(board[1]) < 11 && ft_strlen(board[2]) < 11) \
				if (ft_atoi(board[1]) >= MIN_INT && ft_atoi(board[1]) \
					<= MAX_INT && ft_atoi(board[2]) >= MIN_INT \
											&& ft_atoi(board[2]) <= MAX_INT)
					push_backroom(&lemin->room, temp_line->line, 1, board);
		}
		temp_line = temp_line->next;
	}
	if (!lemin->room)
		exit(0);
}

void		ft_getdata_com(t_lemin *lemin)
{
	t_line		*temp_line;

	/*
	 * get value commentaires !
	 */
	temp_line = lemin->line_copy;
	while (temp_line)
	{
		if(temp_line->line[0] == '#')
			push_back_coment(&lemin->coment, temp_line->line, \
												ft_strlen(temp_line->line));
		temp_line = temp_line->next;
	}
	if (!lemin->coment) /*Check if la liste est NULL */
		exit(0);
	ft_getdata_room(lemin);
}

void		ft_getdata(t_lemin *lemin)
{
	char	*str;
	char	*temp_str;

	str = NULL;
	temp_str = NULL;
	while (get_next_line(0, &str))
	{
		temp_str = lemin->copy_original;
		lemin->copy_original = ft_strjoin(temp_str, str);
		(temp_str != NULL) ? free(temp_str) : 0;
		temp_str = lemin->copy_original;
		lemin->copy_original = ft_strjoin(temp_str, "\n");
		(temp_str != NULL) ? free(temp_str) : 0;
		temp_str = ft_strtrim(str);
		push_backline(&lemin->line_copy, temp_str, ft_strlen(temp_str));
		free(temp_str);
		free(str);
		str = NULL;
	}
	ft_getdata_com(lemin);
}
