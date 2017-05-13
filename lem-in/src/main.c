/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:48:55 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 01:31:56 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"
/*
void		push_backline(t_line **line, char *value_line, int size_line);
t_line		*creat_new_line(char *line, int size_line);
void		debug_line(t_line	*line);
void		clear_line(t_line **line);
void		init_lemin(t_lemin *lemin);*/
static void		init_lemin(t_lemin *lemin)
{
	lemin->copy_original = NULL;
	lemin->line_copy = NULL;
	lemin->coment = NULL;
	lemin->connect = NULL;
	lemin->room = NULL;
	lemin->start = 0;
	lemin->end = 0;
	lemin->nbr_fourmi = -1;
}

int main(void)
{
	t_lemin		lemin;
	init_lemin(&lemin);
	ft_getdata(&lemin);
	return 0;
}
/*
void		init_lemin(t_lemin *lemin)
{
	lemin->model = NULL;
	lemin->connect = NULL;
	lemin->room = NULL;
	lemin->com = NULL;
	lemin->start = 0;
	lemin->end = 0;
	lemin->nbr_fourmi = 0;
}

t_line		*creat_new_line(char *line, int size_line)
{
	t_line	*new_line;
	
	if (!(new_line = (t_line *)malloc(sizeof(*new_line))))
		exit(EXIT_FAILURE);
	new_line->line = strdup(line);
	new_line->size_line = size_line;
	new_line->next = NULL;
	return (new_line);
}

void		push_backline(t_line **line, char *value_line, int size_line)
{
	t_line		*temp_line;
	t_line		*new_line;

	temp_line = *line;
	new_line = NULL;
	if (*line == NULL)
	{
		*line = creat_new_line(value_line, size_line);
		return ;
	}
	new_line = creat_new_line(value_line, size_line);
	while (temp_line->next)
		temp_line = temp_line->next;
	temp_line->next = new_line;
}

void		clear_line(t_line **line)
{
	t_line		*delete;

	delete = NULL;
	while (*line)
	{
		delete = *line;
		*line = (*line)->next;
		free(delete->line);
		free(delete);
	}
}

void		debug_line(t_line	*line)
{
	while (line)
	{
		write(1, line->line, line->size_line);
		write(1, "\n", 1);
		line = line->next;
	}
}*/
