NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
	$(CC) $(FLAGS) bis_main.c get_buf.c parse.c validate.c valid_neighbours.c libft.a -o $(NAME)

test: $(NAME)
	./fillit testfile.fillit