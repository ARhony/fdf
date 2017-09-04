# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 18:40:10 by aramon            #+#    #+#              #
#    Updated: 2017/03/17 20:40:28 by aramon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_LLDB = lldb

NAMELIB = libft/libft.a

SRC = srcs/main.c srcs/read.c srcs/utilities.c srcs/calcul.c srcs/draw.c srcs/key_input.c srcs/init.c srcs/matrice.c

FLAGS = -Wextra -Werror -Wall

INCLUDE = -I ./include

all : $(NAME)

$(NAME):
	gcc $(FLAGS) $(INCLUDE) -o $(NAME) $(SRC) $(NAMELIB) -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

l :
	gcc $(FLAGS) -o $(NAME_LLDB) $(SRC) $(NAMELIB) -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit -g
	lldb ./$(NAME_LLDB)
