# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 12:04:29 by kroselin          #+#    #+#              #
#    Updated: 2019/12/01 13:16:49 by kroselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCs = help_function.c is_valid.c main.c print.c tetras.c algos.c
OBJs = $(SRCs:.c=.o)
HEADER = fillit.h
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJs)
	gcc -o $(NAME) $(OBJs)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< 

clean:
	/bin/rm -f $(OBJs)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
