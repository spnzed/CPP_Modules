# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 22:46:30 by aaronespino       #+#    #+#              #
#    Updated: 2024/09/01 18:09:09 by aaronespino      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES

NAME	= dream_job

SRC		= Account.cpp tests.cpp
OBJ		= $(SRC:.cpp=.o)
CC		= c++
RM		= rm -f

FLAGS	= -Wall -Wextra -Werror -std=c++98

#			RULES

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(FLAGS) -I ./ -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

