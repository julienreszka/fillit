# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 09:54:38 by jreszka           #+#    #+#              #
#    Updated: 2017/01/06 10:14:54 by jreszka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	get_buf.c \
	parse.c \
	num_are_valid.c \
	hash_neighbours_are_valid.c \
	libft.a 

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

test: $(NAME)
	./fillit testfile.fillit