/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 00:58:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/17 00:58:32 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

static int					check_ant(char *ant, t_lemin *lemin)
{
	long long	data;

	if (ft_strlen(ant) > 10)
		return (-1);
	data = ft_atoi(ant);
	if (data > MAX_INT || data <= 0)
		return (-1);
	lemin->nbr_ant = data;
	return (1);
}

static enum e_mod_value		parsing(char *str, t_lemin *lemin)
{
	if (*str == '#')
		return (ft_check_command(str, lemin));
	else if (ft_count_words(str) == 1 && lemin->nbr_ant == -1 && is_digit(str))
	{
		if (check_ant(str, lemin))
			return (NBR_FOURMI);
	}
	else if (ft_count_words(str) == 3)
	{
		if (ft_check_rooms(str, lemin))
			return (ROOM);
	}
	else if (ft_count_words(str) == 1 && ft_strchr(str, '-'))
	{
		if (ft_check_connect(str, lemin))
			return (CONNECT);
	}
	return (INVALID);
}

void						ft_getdata(t_lemin *lemin)
{
	char				*str;
	char				*str_t;
	int					mod;

	str = NULL;
	str_t = NULL;
	while (get_next_line(0, &str))
	{
		if (!ft_strlen(str))
			return (free(str));
		strjoin_noleaks(&lemin->copy_original, str);
		strjoin_noleaks(&lemin->copy_original, "\n");
		str_t = ft_strtrim(str);
		if (!ft_strlen(str_t))
		{
			free(str);
			return (free(str_t));
		}
		ft_memdel((void *)&str);
		str = NULL;
		if ((mod = parsing(str_t, lemin)) == INVALID)
			return (free(str_t));
		push_backline(&lemin->line_copy, str_t, ft_strlen(str_t), mod);
		ft_memdel((void *)&str_t);
	}
}
