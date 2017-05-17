/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:33:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/17 04:11:53 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

enum					e_mod_value
{
	START,
	END,
	COMMENTAIRE,
	CONNECT,
	ROOM,
	NBR_FOURMI,
	INVALID = -1
};

typedef struct			s_line
{
	char				*line;
	int					size_line;
	enum e_mod_value	value;
	int					start;
	int					end;
	struct s_line		*next;
}						t_line;

typedef struct			s_connect
{
	char				*data_1;
	char				*data_2;
	struct s_connect	*next;
}						t_connect;

typedef struct			s_ad_list
{
	char				*room_connect;
	struct s_ad_list	*next;
}						t_ad_list;

typedef struct			s_room
{
	char				*room;
	char				**board;
	int					coord_1;
	int					coord_2;
	int					informs;
	t_ad_list			*connect;
	t_ad_list			*path;
	struct s_room		*next;
}						t_room;

typedef struct			s_path
{
	char				*name_room;
	struct s_path		*next;

}						t_path;

typedef struct			s_lemin
{
	char				*copy_original;
	struct s_line		*line_copy;
	t_connect			*connect;
	t_room				*room;
	t_path				*path;
	int					nbr_ant;
	int					nbr_s;
	int					nbr_e;
}						t_lemin;

void					push_backline(t_line **line, char *value, \
										int size_value, enum e_mod_value mod);
void					ft_clearline(t_line **line);
void					push_backroom(t_room **room, char *value, \
															char **board);
void					push_backconnect(t_connect **connect, \
													char *data_1, char *data_2);
void					ft_getdata(t_lemin *lemin);
char					*manage_string(const char *str, int size);
#endif
