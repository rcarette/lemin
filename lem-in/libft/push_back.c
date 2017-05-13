/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:52:14 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 12:26:31 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_push			*creat_new_list(int data)
{
	t_push		*new_link;

	if (!(new_link = (t_push *)malloc(sizeof(t_push))))
		exit(EXIT_FAILURE);
	new_link->value = data;
	new_link->rotate_top = 0;
	new_link->rotate_bottom = 0;
	new_link->next = NULL;
	return (new_link);
}

void			push_back(t_push **list, int data)
{
	t_push		*new_link;
	t_push		*temp_list;

	temp_list = *list;
	if (*list == NULL)
		*list = creat_new_list(data);
	else
	{
		if (!(new_link = creat_new_list(data)))
			return ;
		while (temp_list->next)
			temp_list = temp_list->next;
		temp_list->next = new_link;
	}
}

void			print_list(t_push *list)
{
	if (!list)
		return ;
	write(1, "\n", 1);
	while (list)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

int				lenght_list(t_push *list)
{
	int		size;

	size = 0;
	if (!list)
		return (0);
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}

void			clear_list(t_push **list)
{
	t_push		*delete;

	delete = *list;
	if (!*list)
		return ;
	while (*list)
	{
		delete = *list;
		(*list) = (*list)->next;
		free(delete);
	}
}
