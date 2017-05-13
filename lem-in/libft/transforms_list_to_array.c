/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms_list_to_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 09:32:05 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 09:40:59 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*transforms_list_to_array(void *liste)
{
	t_push		*list;
	int			*board;
	int			ite;

	ite = -1;
	list = (t_push *)liste;
	if (lenght_list(list) == 0)
		return (NULL);
	if (!(board = (int *)malloc(sizeof(int) * lenght_list(list))))
		exit(EXIT_FAILURE);
	while (list)
	{
		board[++ite] = list->value;
		list = list->next;
	}
	return (board);
}
