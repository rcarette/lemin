/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_a_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 14:15:11 by rcarette          #+#    #+#             */
/*   Updated: 2017/02/23 14:16:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		if_a_character(const char *str, char character)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == character)
			return (1);
	return (0);
}
