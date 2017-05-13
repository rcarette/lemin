/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:13:38 by rcarette          #+#    #+#             */
/*   Updated: 2017/04/26 11:31:27 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_front(t_push **list, int data)
{
	t_push		*new_link;
	t_push		*temp_list;

	if (!list)
		*list = creat_new_list(data);
	else
	{
		new_link = creat_new_list(data);
		temp_list = *list;
		new_link->next = temp_list;
		*list = new_link;
	}
}
