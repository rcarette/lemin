/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_coment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 01:16:06 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 01:20:16 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

static t_com		*creat_new_elem(char *value, int size_value)
{
	t_com		*new_elem;

	new_elem = NULL;

	if (!(new_elem = (t_com *)malloc(sizeof(t_com))))
		exit(EXIT_FAILURE);
	new_elem->value = ft_strdup(value);
	new_elem->size_value = size_value;
	new_elem->next = NULL;
	new_elem->valid = -2;
	return (new_elem);
}

void				push_back_coment(t_com **com, char *value, \
															int size_value)
{
	t_com		*temp_line;
	t_com		*new_elem;

	temp_line = *com;
	if (*com == NULL)
		*com = creat_new_elem(value, size_value);
	else
	{
		new_elem = creat_new_elem(value, size_value);
		while (temp_line->next)
			temp_line = temp_line->next;
		temp_line->next = new_elem;
	}
}

