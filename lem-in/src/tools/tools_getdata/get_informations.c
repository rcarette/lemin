/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 15:12:12 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 17:37:55 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/data.h"
#include "../../../inc/main.h"

void	get_quote(t_line **line)
{
	if (!ft_strcmp((*line)->line, "##start"))
		(*line)->value = START;
	else if (!ft_strcmp((*line)->line, "##end"))
		(*line)->value = END;
	else
		(*line)->value = COMMENTAIRE;
}

char	*manage_string(const char *str, int size)
{
	char	*copy;
	int		ite;

	ite = -1;
	if (!(copy = (char *)malloc(sizeof(char) * (size + 1))))
		exit(EXIT_FAILURE);
	ft_memset(copy, '\0', (size + 1));
	while (str[++ite])
		copy[ite] = (str[ite] == ' ' || str[ite] == '\t') ? 4 : str[ite];
	return (copy);
}

void	get_room(t_line **line)
{
	char		*copy;
	char		**board;
	int			ite;
	long long	data[2];

	ite = -1;
	copy = manage_string((*line)->line, (*line)->size_line);
	board = ft_strsplit(copy, 4);
	ft_memdel((void *)&copy);
	if ((!is_digit(board[1]) || !is_digit(board[2])) || \
						(ft_strlen(board[1]) > 10 || ft_strlen(board[2]) > 10))
	{
		(*line)->value = INVALID;
		clear_tab(board);
		return ;
	}
	data[0] = ft_atoi(board[1]);
	data[1] = ft_atoi(board[2]);
	clear_tab(board);
	if ((data[0] >= 0 && data[0] <= MAX_INT) \
									&& (data[1] >= 0 && data[1] <= MAX_INT))
	{
		(*line)->value = ROOM;
		return ;
	}
	(*line)->value = INVALID;
}

void	get_connect(t_line **line)
{
	int		nbr;

	nbr = ft_strlen_n((*line)->line, '-');
	if (!nbr || nbr > 1)
		(*line)->value = INVALID;
	else if (nbr == 1)
		(*line)->value = CONNECT;
}
