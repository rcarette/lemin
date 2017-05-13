/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 12:05:56 by rcarette          #+#    #+#             */
/*   Updated: 2017/04/25 12:29:00 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *nptr)
{
	int					negative;
	long long			result;
	int					size;

	size = *nptr;
	if (size < 0)
		return (0);
	negative = 1;
	result = 0;
	while (*nptr <= 32)
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		negative = -1;
	}
	if ((*nptr == '-' || *nptr == '+') && negative == -1)
		return (0);
	(*nptr == '+') ? nptr++ : 0;
	while (*nptr >= '0' && *nptr <= '9')
		result = ((result * 10) + *nptr++ - '0');
	return (result * negative);
}
