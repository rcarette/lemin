/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns_big_value_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 08:34:07 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 08:45:03 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		returns_big_value_array(int *board, int size)
{
	int		data;
	int		i;

	i = -1;
	data = board[i + 1];
	while (++i < size)
		if (data <= board[i])
			data = board[i];
	return (data);
}
