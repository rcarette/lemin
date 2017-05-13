/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:48:55 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 13:49:50 by rcarette         ###   ########.fr       */
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
	lemin->start = 0;
	lemin->end = 0;
	lemin->nbr_fourmi = -1;
}

int main(void)
{
	t_lemin		lemin;
	init_lemin(&lemin);
	ft_getdata(&lemin);
	return 0;
}
