/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:58:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 19:58:37 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

static int		if_a_overflow_coord(char *s1, char *s2)
{
	long long	data_1;
	long long	data_2;

	if (ft_strlen(s1) > 11 || ft_strlen(s2) > 11)
		return (0);
	else
	{
		data_1 = ft_atoi(s1);
		data_2 = ft_atoi(s2);
		if (data_1 < MIN_INT || data_1 > MAX_INT)
			return (0);
		if (data_2 < MIN_INT || data_2 > MAX_INT)
			return (0);
		if (data_1 < 0 || data_2 < 0)
			return (0);
	}
	return (1);
}

static int		if_a_room(char *s1, char *s2)
{
	if (!is_digit(s1) || !is_digit(s2))
		return (INVALID);
	if (!(if_a_overflow_coord(s1, s2)))
		return (INVALID);
	return (ROOM);
}

static int		if_a_connect(char *str)
{
	char	**board;

	if (ft_strchr(str, '-') && ft_strlen_n(str, '-') != 1)
		return (0);
	if (ft_strlen_matrice(board = ft_strsplit(str, '-')) != 2)
		return (clear_tab(board));
	return (CONNECT);
}

static void		ft_getnbr_fourmi(t_lemin *lemin)
{
	t_line		*temp_line;
	long long	data;

	temp_line = lemin->line_copy;
	while (ft_strlen(temp_line->line) == 0)
		temp_line = temp_line->next;
	if (!is_digit(temp_line->line))
	{
		temp_line->value = INVALID;
		return ;
	}
	if (ft_strlen(temp_line->line) > 11)
		temp_line->value = INVALID;
	else
	{
		data = ft_atoi(temp_line->line);
		if (data < 0 || data > MAX_INT)
			temp_line->value = INVALID;
		else
			temp_line->value = NBR_FOURMI;
	}
}

static void		lexer(t_lemin *lemin)
{
	t_line		*temp_line;
	char		**board;

	ft_getnbr_fourmi(lemin);
	temp_line = lemin->line_copy;
	while (temp_line)
	{
		if (temp_line->value == NBR_FOURMI)
		{
			temp_line = temp_line->next;
			continue ;
		}
		if (!ft_strlen(temp_line->line))
			temp_line->value = INVALID;
		else if (temp_line->line[0] == '#')
		{
			if (!ft_strcmp(temp_line->line, "##start"))
				temp_line->value = START;
			else if (!ft_strcmp(temp_line->line, "##end"))
				temp_line->value = END;
			else
				temp_line->value = COMMENTAIRE;
		}
		else
		{
			board = ft_strsplit(temp_line->line, ' ');
			if (ft_strlen_matrice(board) == 3)
				temp_line->value = if_a_room(board[1], board[2]);
			else if (if_a_connect(temp_line->line))
				temp_line->value = CONNECT;
			else
				temp_line->value = INVALID;
			clear_tab(board);
		}
		temp_line = temp_line->next;
	}
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
	if (lemin->copy_original == NULL || lemin->copy_original == NULL)
		exit(0);
	lexer(lemin);
	while (lemin->line_copy)
	{
		printf("Value: %s ; enum : %d\n", lemin->line_copy->line, lemin->line_copy->value);
		lemin->line_copy = lemin->line_copy->next;
	}
}

