# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jreszka <jreszka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 09:54:38 by jreszka           #+#    #+#              #
#    Updated: 2017/01/10 10:48:31 by jreszka          ###   ########.fr        #
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
	ft_tets_chars.c \
	ft_solve.c \
	libft.a 

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

test: $(NAME)
	./fillit testfile.fillit