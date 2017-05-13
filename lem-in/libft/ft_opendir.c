/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:24:11 by rcarette          #+#    #+#             */
/*   Updated: 2017/02/23 14:19:46 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

DIR		*ft_opendir(const char *str)
{
	DIR		*rep;

	if (!str)
		return (NULL);
	if (ft_strlen(str) == 0)
		return (NULL);
	if (!(rep = opendir(str)))
		return (NULL);
	return (rep);
}
