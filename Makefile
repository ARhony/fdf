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

LIBFT_DIR = ./libft/
NAMELIBFT = ./libft/libft.a

MINILIBX_DIR = minilibx/
NAMEMLX = minilibx/libmlx.a

LIB = $(LIBFT_DIR) $(NAMELIBFT)
MLX = $(MINILIBX_DIR) $(NAMEMLX)

SRC = srcs/main.c 		\
	  srcs/read.c 		\
	  srcs/utilities.c 	\
	  srcs/calcul.c 	\
	  srcs/draw.c 		\
	  srcs/key_input.c 	\
	  srcs/init.c 		\
	  srcs/matrice.c

FLAGS = -Wextra -Werror -Wall -O3
FRAMEWORK = -framework OpenGL -framework AppKit

INCLUDE = -I ./include

all : $(LIB) $(MLX) $(NAME)

$(LIB):
	@$(MAKE) -C $(LIBFT_DIR) re

$(MLX):
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME):
	@gcc $(FLAGS) $(INCLUDE) -o $(NAME) $(SRC) $(NAMELIBFT) -I minilibx -L minilibx -lmlx $(FRAMEWORK)

clean :
	@rm -f $(OBJECT)

fclean : clean
	cd $(LIBFT_DIR) && make fclean
	cd $(MINILIBX_DIR) && make clean
	rm -f $(NAME)

re : fclean all

