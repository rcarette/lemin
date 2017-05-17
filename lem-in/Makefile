# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:04:47 by rcarette          #+#    #+#              #
#    Updated: 2017/05/17 03:19:06 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -fsanitize=address
CC = clang $(FLAGS)
INC = ../../include
LIBFT = libft/
INC_LIB = libft/libft.h
ALL_INC = -I $(INC) -I $(INC_LIB)
OBJS = $(SRCS:%.c=%.o)

SRCS = src/main.c\
	   src/ft_getdata.c\
	   src/tools/ft_exit.c\


TOOLS = src/tools/push_backline.c\
		src/tools/push_backroom.c\
		src/tools/push_backconnect.c\
		src/tools/ft_creat_graph.c\

TOOLS_GET_DATA = src/tools/tools_getdata/get_informations.c\

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) -g -o $(NAME) $(SRCS) $(TOOLS) $(TOOLS_GET_DATA) $(ALL_INC)  -L $(LIBFT) -lft

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
