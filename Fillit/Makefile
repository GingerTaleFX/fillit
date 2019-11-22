# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:04:29 by kroselin          #+#    #+#              #
#    Updated: 2019/11/22 14:23:11 by kroselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCs = help_function.c is_valid.c main.c print.c tetras.c algos.c
OBJs = $(SRCs:.c=.o)
HEADER = fillit.h
FLAGS = -Wall -Wextra -Werror
# LIB_HDR = /libft/libft.h
# FILL_HDR = fillit.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCs)
	gcc -o $(NAME) $(OBJs)

clean:
	/bin/rm -f $(OBJs)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
