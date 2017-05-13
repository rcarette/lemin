/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_n_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 04:18:33 by rcarette          #+#    #+#             */
/*   Updated: 2017/02/26 04:20:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_n_character(const char *str, int character)
{
	int		ite;
	int		size;

	ite = -1;
	size = 0;
	while (str[++ite])
		if (str[ite] == character)
			++size;
	return (size);
}
