# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 22:27:56 by aaronespino       #+#    #+#              #
#    Updated: 2024/09/02 00:21:36 by aaronespino      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES

NAME	= violence

SRC		= HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
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

