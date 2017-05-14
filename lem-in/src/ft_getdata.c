/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:58:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 23:55:28 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

static void		lexer(t_lemin *lemin)
{
	t_line		*temp_line;

	temp_line = lemin->line_copy;
	getnbr_fumy(lemin);
	while (temp_line)
	{
		if (temp_line->value == NBR_FOURMI)
		{
			temp_line = temp_line->next;
			continue ;
		}
		else if (temp_line->line[0] == '#')
			get_quote(&temp_line);
		else if (ft_count_words(temp_line->line) == 3)
			get_room(&temp_line);
		else if (ft_count_words(temp_line->line) == 1)
			get_connect(&temp_line);
		else
		{
			temp_line->value = INVALID;
		}
		temp_line = temp_line->next;
	}
}

void		ft_getdata(t_lemin *lemin)
{
	char	*str;
	char	*temp_str;

	str = NULL;
	temp_str = NULL;
	while (get_next_line(0, &str))
	{
		strjoin_noleaks(&lemin->copy_original, str);
		strjoin_noleaks(&lemin->copy_original, "\n");
		temp_str = ft_strtrim(str);
		push_backline(&lemin->line_copy, temp_str, ft_strlen(temp_str));
		free(temp_str);
		free(str);
		str = NULL;
	}
	if (lemin->copy_original == NULL || lemin->copy_original == NULL)
		exit(0);
	lexer(lemin);
}

