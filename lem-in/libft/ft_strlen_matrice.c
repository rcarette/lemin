/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:08:24 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 15:09:36 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_matrice(char **board)
{
	int		ite;
	int		size;

	ite = -1;
	size = 0;
	while (board[++ite])
		++size;
	return (size);
}
