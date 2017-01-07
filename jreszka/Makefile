# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 09:54:38 by jreszka           #+#    #+#              #
#    Updated: 2017/01/07 11:56:29 by jreszka          ###   ########.fr        #
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
	ft_print_2d_table.c \
	ft_int_sqrt.c \
	ft_init_map.c \
	ft_build_tets.c \
	ft_tets_ref_points.c \
	libft.a 

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

test: $(NAME)
	./fillit testfile.fillit