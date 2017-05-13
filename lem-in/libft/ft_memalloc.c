/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 19:43:51 by rcarette          #+#    #+#             */
/*   Updated: 2017/03/03 15:15:34 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size, size_t ssize)
{
	void	*new_memory;

	if (size)
	{
		if (!(new_memory = (void *)malloc(sizeof(ssize) * size)))
			exit(EXIT_FAILURE);
		ft_memset(new_memory, '\0', size);
		return (new_memory);
	}
	return (NULL);
}
