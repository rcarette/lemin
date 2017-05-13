/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 07:12:42 by rcarette          #+#    #+#             */
/*   Updated: 2017/02/04 07:18:59 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		exit(EXIT_FAILURE);
	ft_memset(new_str, '\0', size + 1);
	return (new_str);
}
