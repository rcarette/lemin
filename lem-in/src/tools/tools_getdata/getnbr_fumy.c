/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr_fumy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:10:21 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 15:11:07 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/main.h"
#include "../../../inc/data.h"

void	getnbr_fumy(t_lemin *lemin)
{
	t_line		*temp_line;
	char		*copy_line;
	long long	data;

	temp_line = lemin->line_copy;
	while (ft_strlen(temp_line->line) == 0)
		temp_line = temp_line->next;
	if (ft_count_words(temp_line->line) != 1)
	{
		temp_line->value = INVALID;
		return ;
	}
	copy_line = ft_strdup(temp_line->line);
	if ((copy_line[0] == '-' || ft_strlen(copy_line) > 10))
		temp_line->value = INVALID;
	else if (!(is_digit(copy_line)))
	{
		temp_line->value = INVALID;
		return ;
	}
	data = ft_atoi(copy_line);
	temp_line->value = (data <= 0 || data > MAX_INT) ? INVALID : NBR_FOURMI;
	ft_memdel((void *)&copy_line);
}
