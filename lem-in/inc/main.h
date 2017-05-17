/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:26:44 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/16 15:33:41 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "../libft/libft.h"
# include "data.h"
void					ft_exit(t_lemin *lemin);
int						ft_check_command(char *str, t_lemin *lemin);
int						ft_check_connect(char *str, t_lemin *lemin);
int						ft_check_all_connect(char **board, t_lemin *lemin);
int						ft_check_rooms(char *str, t_lemin *lemin);
int						check_all_room_list(char *room_name, t_lemin *lemin);
void					ft_creat_graph(t_lemin *lemin);

#endif
