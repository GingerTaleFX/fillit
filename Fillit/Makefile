# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:04:29 by kroselin          #+#    #+#              #
#    Updated: 2019/11/16 22:05:03 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCs = *.c libft/*.c
OBJs = *.o
FLAGS = -Wall -Wextra -Werror
# LIB_HDR = /libft/libft.h
# FILL_HDR = fillit.h

all: $(NAME)

$(NAME):
	gcc -c $(SRCs)
	gcc -o $(NAME) $(OBJs)
# 	ar rc $(NAME) $(OBJs)

clean:
	/bin/rm -f $(OBJs)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all