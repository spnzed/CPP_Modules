# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 22:27:56 by aaronespino       #+#    #+#              #
#    Updated: 2024/09/12 12:28:03 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES

NAME	= animal

SRC		= main.cpp Dog.cpp Cat.cpp Animal.cpp
OBJ		= $(SRC:.cpp=.o)
CC		= c++
RM		= rm -f

FLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -fsanitize=address

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

