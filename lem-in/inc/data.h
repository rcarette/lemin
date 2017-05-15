/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:33:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/15 17:10:27 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

enum					s_mod_value
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
	enum s_mod_value	value;
	struct s_line		*next;
}						t_line;

typedef struct			s_connect
{
	char				*data_1;
	char				*data_2;
	struct s_connect	*next;
}						t_connect;

typedef struct			s_room
{
	char				*room;
	char				**board;
	struct s_room		*next;
}						t_room;

typedef struct			s_com
{
	char				*value;
	int					size_value;
	int					valid; /* -1 || 0 start || 1 end*/
	struct s_com		*next;

}						t_com;

typedef struct			s_lemin
{
	char				*copy_original;
	struct s_line		*line_copy;
	t_connect			*connect;
	t_room				*room;
	t_com				*coment;
	int					nbr_ant;
}						t_lemin;

void					push_backline(t_line **line, char *value, \
										int size_value, enum s_mod_value mod);
void					ft_clearline(t_line **line);
void					push_back_coment(t_com **com, char *value, \
														int size_value);
void					push_backroom(t_room **room, char *value, \
															char **board);
void					push_backconnect(t_connect **connect, \
													char *data_1, char *data_2);
void					ft_getdata(t_lemin *lemin);
void					getnbr_fumy(t_lemin *lemin);
int						check_nbr_fumy(t_lemin *lemin);
void					get_quote(t_line **line);
char					*manage_string(const char *str, int size);
void					get_room(t_line **line);
void					get_connect(t_line **line);
int						check_dupliq_rooms(t_lemin *lemin);
int						check_command(t_lemin *lemin);
int						check_room_and_connect(t_lemin *lemin);
int						if_room_after_command(t_lemin *lemin,\
													enum s_mod_value mod);
#endif
