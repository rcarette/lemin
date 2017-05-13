/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_remove_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 13:01:59 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 12:25:24 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_last(t_push **list, int data)
{
	t_push		*temporary;
	t_push		*prev;

	temporary = (*list);
	while (temporary->next)
	{
		prev = temporary;
		temporary = temporary->next;
	}
	if (temporary->value == data)
	{
		free(temporary);
		prev->next = NULL;
		return (1);
	}
	return (0);
}

static int		check_first(t_push **list, int data)
{
	t_push		*delete;

	if ((*list)->value == data)
	{
		delete = *list;
		*list = (*list)->next;
		free(delete);
		return (1);
	}
	return (0);
}

static int		check_middle(t_push **list, int data)
{
	t_push		*temporary;
	t_push		*prev;
	t_push		*next;

	temporary = *list;
	while (temporary)
	{
		next = temporary->next;
		if (temporary->value == data)
		{
			prev->next = next;
			free(temporary);
			return (1);
		}
		prev = temporary;
		temporary = temporary->next;
	}
	return (0);
}

void			if_remove_list(t_push **list, int data)
{
	if (!*list)
		return ;
	else if (lenght_list(*list) == 1 && data == (*list)->value)
	{
		free(*list);
		*list = NULL;
		return ;
	}
	else if (check_last(list, data))
		return ;
	else if (check_first(list, data))
		return ;
	check_middle(list, data);
}
