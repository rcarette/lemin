/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getintsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 03:01:34 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/09 00:55:52 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getintsize(long long data)
{
	char	*str;
	int		size;

	str = ft_itoa(data);
	size = ft_strlen(str);
	free(str);
	return (size);
}
