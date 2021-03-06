/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:18:08 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 16:35:10 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_digit(const char *s1)
{
	int		ite;

	ite = -1;
	(*s1 == '-' || *s1 == '+') ? ++ite : 0;
	while (s1[++ite])
		if (!ft_isdigit(s1[ite]))
			return (0);
	return (1);
}
