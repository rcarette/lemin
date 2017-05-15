/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimited_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:28:15 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 15:30:58 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*delimited_string(const char *str)
{
	char	*copy;
	int		ite;

	ite = -1;
	if (!(copy = ft_strdup(str)))
		exit(EXIT_FAILURE);
	while (str[++ite])
		copy[ite] = (str[ite] == ' ' || str[ite] == '\t') ? 4 : str[ite];
	return (copy);
}
