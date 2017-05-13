/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:44:37 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/08 12:26:14 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_char(char *buff, char character, int *ite)
{
	int		i;

	if (!buff || !character)
		return ;
	i = -1;
	while (buff[++i])
		;
	buff[i] = character;
	buff[i + 1] = '\0';
	*ite += (1);
}
