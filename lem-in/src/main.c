/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:48:55 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/14 23:57:28 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/data.h"
#include "../inc/main.h"

static void		ft_exit(t_lemin *lemin)
{
	(void)lemin;
	printf("Passage\n");
	exit(0);
}

static void		init_lemin(t_lemin *lemin)
{
	lemin->copy_original = NULL;
	lemin->line_copy = NULL;
	lemin->coment = NULL;
	lemin->connect = NULL;
	lemin->room = NULL;
	lemin->start = 0;
	lemin->end = 0;
	lemin->nbr_fourmi = -1;
}

int main(void)
{
	t_lemin		lemin;
	init_lemin(&lemin);
	ft_getdata(&lemin); /* copy original + stock line maillon + decrit chaque lignes ! */
	/*while (lemin.line_copy)
	{
		printf("%s %d\n", lemin.line_copy->line, lemin.line_copy->value);
		lemin.line_copy = lemin.line_copy->next;
	}*/
	if (!check_nbr_fumy(&lemin)) /*Check si il y a des fumys !! */
		ft_exit(&lemin);
	else if (!check_command(&lemin)) /*Check si il y a ##start && ##end ! */
		ft_exit(&lemin);
	else if (!check_room_and_connect(&lemin)) /*Check si il y a ROOM && CONNECT */
		ft_exit(&lemin);
	else if (!if_room_after_command(&lemin, START)) /*Check si la command ##start est suivit d'une room*/
		ft_exit(&lemin);
	else if (!if_room_after_command(&lemin, END)) /*Check si la command ##end est suivit d'une room */
		ft_exit(&lemin);
	else if (!check_dupliq_rooms(&lemin)) /* check les doublons des rooms !! */
		ft_exit(&lemin);
	/*else if (!check_dupliq_connect(&lemin))
		ft_exit(&lemin);*/
	printf("%s\n", lemin.copy_original);
	return 0;
}
