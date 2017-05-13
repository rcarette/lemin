/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_n_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:19:09 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 18:22:22 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_n(const char *str, char character)
{
	int		ite;
	int		size;

	ite = -1;
	size = 0;
	if (!str || ft_strlen(str) == 0)
		return (0);
	while (str[++ite])
		if (str[ite] == character)
			++size;
	return (size);
}
