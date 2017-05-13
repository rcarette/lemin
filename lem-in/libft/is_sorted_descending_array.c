/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_descending_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:44:03 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 10:55:15 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_sorted_descending_array(int *board, int size)
{
	int		ite;
	int		data;

	ite = -1;
	while (++ite < (size - 1))
	{
		data = board[ite];
		if (data > board[ite + 1])
			continue ;
		else
			return (0);
	}
	return (1);
}
