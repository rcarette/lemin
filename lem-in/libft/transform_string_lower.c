/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_string_lower.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:48:18 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 15:16:29 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		transform_string_lower(char *str, char *model)
{
	char	*new_str;
	int		ite;
	int		jte;

	if (!ft_strlen(str))
		return (-1);
	ite = -1;
	jte = 0;
	if (!(new_str = ft_strdup(str)))
		exit(EXIT_FAILURE);
	while (new_str[++ite])
		if (new_str[ite] >= 65 && new_str[ite] <= 90)
			new_str[ite] += (32);
	if (!ft_strcmp(new_str, model))
		jte = 1;
	ft_memdel((void *)&new_str);
	return (jte);
}
