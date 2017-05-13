/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 09:44:24 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/03 09:49:24 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_array(int *board, int size)
{
	int		ite;
	char	*value;

	ite = -1;
	while (board[++ite])
	{
		value = ft_itoa(board[ite]);
		write(1, value, ft_strlen(value));
		ft_memdel((void *)&value);
		(ite != size - 1) ? write(1, " ", 1) : 0;
	}
	write(1, "\n", 1);
}
