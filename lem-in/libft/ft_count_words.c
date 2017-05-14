/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 12:17:00 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 17:21:21 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*manage(const char *str, int size)
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

static int		nbr_word(const char *str)
{
	int		ite;
	int		size;
	char	**board;

	size = 0;
	ite = -1;
	board = ft_strsplit((char *)str, 4);
	while (board[++ite])
		++size;
	clear_tab(board);
	return (size);
}

int				ft_count_words(const char *str)
{
	char	*copy;
	int		size;

	if (!ft_strlen(str))
		return (0);
	copy = manage(str, ft_strlen(str));
	size = nbr_word(copy);
	ft_memdel((void *)&copy);
	return (size);
}
