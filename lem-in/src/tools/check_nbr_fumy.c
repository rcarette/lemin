/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr_fumy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:34:56 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 15:41:12 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/data.h"
#include "../../inc/main.h"

int		check_nbr_fumy(t_lemin *lemin)
{
	t_line		*temp_line;

	temp_line = lemin->line_copy;
	while (temp_line)
	{
		if (temp_line->value == NBR_FOURMI)
		{
			lemin->nbr_fourmi = ft_atoi(temp_line->line);
			return (1);
		}
		temp_line = temp_line->next;
	}
	lemin->nbr_fourmi = 0;
	return (0);
}
