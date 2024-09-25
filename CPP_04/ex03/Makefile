# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 22:46:30 by aaronespino       #+#    #+#              #
#    Updated: 2024/09/25 17:40:36 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES

NAME	= materia

SRC_DIR = src/

SRC		= AMateria.cpp Cure.cpp Ice.cpp main.cpp MateriaSource.cpp Character.cpp

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.d))

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD #-pedantic -g -fsanitize=address
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

-include $(DEP)

.PHONY: all clean fclean re