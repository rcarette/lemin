/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 12:09:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/02/04 07:14:09 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size_s;
	char	*new_str;

	size_s = ft_strlen(s);
	if (!(new_str = (char *)malloc(sizeof(char) * (size_s + 1))))
		exit(EXIT_FAILURE);
	ft_memset(new_str, '\0', (size_s + 1));
	ft_memcpy(new_str, s, size_s);
	return (new_str);
}
