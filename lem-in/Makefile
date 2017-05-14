# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:04:47 by rcarette          #+#    #+#              #
#    Updated: 2017/05/14 01:14:56 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
CC = clang $(FLAGS)
INC = ../../include
LIBFT = libft/
INC_LIB = libft/libft.h
ALL_INC = -I $(INC) -I $(INC_LIB)
OBJS = $(SRCS:%.c=%.o)

SRCS = src/main.c\
	   src/ft_getdata.c\

TOOLS = src/tools/push_backline.c\
		src/tools/push_back_coment.c\
		src/tools/push_backroom.c\

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) -o $(NAME) $(SRCS) $(TOOLS) $(ALL_INC)  -L $(LIBFT) -lft

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
