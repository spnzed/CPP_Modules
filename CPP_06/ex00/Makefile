# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 22:46:30 by aaronespino       #+#    #+#              #
#    Updated: 2024/10/07 13:19:32 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES

NAME	= Conversion

SRC_DIR = src/

SRC		=	ScalarConverter.cpp main.cpp

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.d))

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -pedantic #-fsanitize=address -g
RM		= rm -f
INCLUDE = -I ./

#			RULES

all		:	$(NAME)

$(NAME)	:	$(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $@

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEP)

fclean:	clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean $(NAME)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

-include $(DEP)

.PHONY: all clean fclean re