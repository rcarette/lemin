/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 10:27:21 by rcarette          #+#    #+#             */
/*   Updated: 2017/03/31 12:04:30 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup_x(char *line_command, char character)
{
	char	*new_line;
	int		i;

	i = -1;
	if (!line_command)
		return (NULL);
	if (!(ft_strchr(line_command, character)))
		return (ft_strdup(line_command));
	if (!(new_line = (char *)malloc(sizeof(char) * ft_strlen(line_command))))
		exit(EXIT_FAILURE);
	ft_memset(new_line, '\0', ft_strlen(line_command));
	while (line_command[i] != ' ')
		new_line[i] = line_command[i];
	return (new_line);
}
