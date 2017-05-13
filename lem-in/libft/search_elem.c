/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 18:58:42 by rcarette          #+#    #+#             */
/*   Updated: 2017/04/29 19:00:58 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		search_elem(t_push *list, int data)
{
	while (list)
	{
		if (list->value == data)
			return (1);
		list = list->next;
	}
	return (0);
}
