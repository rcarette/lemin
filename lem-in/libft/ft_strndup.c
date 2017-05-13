/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 02:10:31 by rcarette          #+#    #+#             */
/*   Updated: 2017/03/03 15:14:01 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int size)
{
	char	*new_str;
	int		i;

	i = -1;
	if (!str || *str == '\0')
		return (ft_strnew(1));
	new_str = ft_memalloc((size + 1), sizeof(char));
	new_str[size + 1] = '\0';
	while (++i < size)
		new_str[i] = str[i];
	return (new_str);
}
