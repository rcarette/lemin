/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_backconnect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:05:53 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 17:11:00 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

static t_connect		*creat_new_elem(char *data_1, char *data_2)
{
	t_connect		*new_elem;

	new_elem = NULL;

	if (!(new_elem = (t_connect *)malloc(sizeof(t_connect))))
		exit(EXIT_FAILURE);
	new_elem->data_1 = ft_strdup(data_1);
	new_elem->data_2 = ft_strdup(data_2);
	new_elem->next = NULL;
	return (new_elem);
}

void				push_backconnect(t_connect **connect, \
													char *data_1, char *data_2)
{
	t_connect		*temp_line;
	t_connect		*new_elem;

	temp_line = *connect;
	if (*connect == NULL)
		*connect = creat_new_elem(data_1, data_2);
	else
	{
		new_elem = creat_new_elem(data_1, data_2);
		while (temp_line->next)
			temp_line = temp_line->next;
		temp_line->next = new_elem;
	}
}
