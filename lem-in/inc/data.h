/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:33:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/13 02:30:07 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

enum	s_mod_value
{
		COMMEMTAIRE,
		CONNECT,
		ROOM,
		INVALID = -1
};

typedef struct		s_line
{
	char			*line;
	int				size_line;
	enum s_mod_value	value;
	struct s_line	*next;
}					t_line;

typedef struct		s_connect
{
	char			*data_1;
	char			*data_2;
	int				nbr_a;
	struct s_connect	*next;
}					t_connect;

typedef struct		s_room
{
	char			*room;
	int				valid;
	char			**board;
	struct s_room	*next;
}					t_room;

typedef struct		s_com
{
	char			*value;
	int				size_value;
	int				valid; /* -1 || 0 start || 1 end*/
	struct s_com	*next;

}					t_com;

typedef struct		s_lemin
{
	char			*copy_original;
	struct s_line	*line_copy;
	t_connect		*connect;
	t_room			*room;
	t_com			*coment;
	int				start;
	int				end;
	int				nbr_fourmi;
}					t_lemin;

void				push_backline(t_line **line, char *value, \
														int size_value);
void				push_back_coment(t_com **com, char *value, \
														int size_value);
void				push_backroom(t_room **room, char *value, \
												int valid, char **board);
void				ft_getdata(t_lemin *lemin);
#endif
