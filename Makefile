# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 16:59:50 by thou              #+#    #+#              #
#    Updated: 2017/01/05 15:35:49 by thou             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
LIB = ./libft
SRC = main.c\
		rangetab.c\
		readfile.c\
		solution.c\
		tetrimino.c\
		ft_check.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc -c $(FLAGS) $(SRC)
	gcc $(OBJ) -o $(NAME) -L$(LIB) -lft

clean:
	make clean -C $(LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -rf $(NAME)

re: fclean all
	make re -C $(LIB)
