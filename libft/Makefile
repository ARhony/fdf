# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aramon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 17:13:10 by aramon            #+#    #+#              #
#    Updated: 2017/03/16 21:48:52 by aramon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS =	-Wall -Werror -Wextra
SRC = ft_putchar.c ft_putstr.c ft_strlen.c ft_strcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_putnbr.c ft_strnstr.c ft_atoi.c ft_strcmp.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isupper.c ft_islower.c ft_lastword.c ft_wordcount.c ft_isspace.c ft_strsplit_seg.c get_next_line.c get_next_line_num.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
