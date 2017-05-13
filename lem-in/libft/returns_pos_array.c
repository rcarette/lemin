/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns_pos_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 08:55:41 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 12:25:50 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		returns_pos_array(int *board, int size, int data)
{
	int		i;

	if (!size || size == 0)
		return (-1);
	i = 0;
	if (data == board[i])
		return (1);
	while (++i < size)
		if (data == board[i])
			return (i + 1);
	return (-1);
}
