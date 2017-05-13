/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   returns_small_value_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 08:31:12 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 23:20:27 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		returns_small_value_array(int *board, int size)
{
	int		data;
	int		i;

	i = 0;
	data = board[i];
	while (++i < size)
		if (data >= board[i])
			data = board[i];
	return (data);
}
