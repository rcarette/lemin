/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:48:55 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 19:21:04 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

static void		init_lemin(t_lemin *lemin)
{
	lemin->copy_original = NULL;
	lemin->line_copy = NULL;
	lemin->coment = NULL;
	lemin->connect = NULL;
	lemin->room = NULL;
	lemin->nbr_ant = -1;
}

static void		ft_checking(t_lemin *lemin)
{
	if (!lemin->line_copy)
		ft_exit(lemin);
	if (!lemin->nbr_ant)
		ft_exit(lemin);
	else if (!lemin->room)
		ft_exit(lemin);
	else if (!lemin->connect)
		ft_exit(lemin);

}

void	debug(t_lemin *lemin)
{
	t_line		*line;

	line = lemin->line_copy;
	while (line)
	{
		printf("%s\n", line->line);
		line = line->next;
	}
}

int main(void)
{
	t_lemin		lemin;
	init_lemin(&lemin);
	ft_getdata(&lemin);
	ft_checking(&lemin);
	//debug(&lemin);
	/*if (!check_nbr_fumy(&lemin))
		ft_exit(&lemin);
	else if (!check_command(&lemin))
		ft_exit(&lemin);
	else if (!check_room_and_connect(&lemin))
		ft_exit(&lemin);
	else if (!if_room_after_command(&lemin, START))
		ft_exit(&lemin);
	else if (!if_room_after_command(&lemin, END))
		ft_exit(&lemin);
	else if (!check_dupliq_rooms(&lemin))
		ft_exit(&lemin);*/
	return 0;
}
