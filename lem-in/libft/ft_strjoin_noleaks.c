/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_noleaks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 22:58:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 23:53:09 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		stock(char **str_1, char *str_2)
{
	*str_1 = ft_memalloc((ft_strlen(*str_1) + 1), sizeof(char));
	ft_memcpy(*str_1, str_2, ft_strlen(str_2) + 1);
}

void			strjoin_noleaks(char **str_1, char *str_2)
{
	char	*sauve_str_1;
	int		size_1;
	int		size_2;

	if (*str_1 == NULL)
		stock(str_1, str_2);
	else
	{
		size_1 = ft_strlen(*str_1);
		size_2 = ft_strlen(str_2);
		sauve_str_1 = ft_strdup(*str_1);
		free(*str_1);
		*str_1 = NULL;
		*str_1 = (char *)ft_memalloc((size_1 + size_2 + 1), sizeof(char));
		ft_strcpy(*str_1, sauve_str_1);
		ft_strcat(*str_1, str_2);
		free(sauve_str_1);
	}
}
