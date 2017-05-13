/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:34:11 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 10:50:28 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_sorted_ascending_array(int *board, int size)
{
	int		ite;
	int		data;

	ite = -1;
	while (++ite < (size - 1))
	{
		data = board[ite];
		if (data < board[ite + 1])
			continue ;
		else
			return (0);
	}
	return (1);
}
