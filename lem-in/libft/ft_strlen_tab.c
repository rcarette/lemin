/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:14:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 16:16:41 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_tab(char **board)
{
	int		ite;
	int		size;
	
	if (board[0] == NULL)
		return (0);
	if (!board)
		return (0);
	size = 0;
	ite = -1;
	while (board[++ite])
		++size;
	return (size);
}
