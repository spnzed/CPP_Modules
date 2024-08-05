# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 17:25:25 by aaronespino       #+#    #+#              #
#    Updated: 2024/08/05 17:26:25 by aaronespino      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#			VARIABLES
SRC		= megaphone.cpp
OBJ		= $(SRC:*.cpp=*.o)
CC		= g++
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= megaphone

#			RULES
all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re 
