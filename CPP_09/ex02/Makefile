# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 22:46:30 by aaronespino       #+#    #+#              #
#    Updated: 2024/11/25 19:54:50 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES

NAME	= PmergeMe

SRC_DIR = src/

SRC		=	main.cpp argUtils.cpp														\
			dequeBinarySearch.cpp dequeJacobSthal.cpp dequeMSI.cpp dequeUtils.cpp 		\
			vectorBinarySearch.cpp vectorJacobSthal.cpp vectorMSI.cpp vectorUtils.cpp 	\

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.d))

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -pedantic -g -O2
RM		= rm -f
INCLUDE = -I ./

SIZE ?= 1000

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

run: all
	./$(NAME) `shuf -i 1-$(SIZE) -n $(SIZE) | tr "\n" " "`

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) `shuf -i 1-$(SIZE) -n $(SIZE) | tr "\n" " "`

-include $(DEP)

.PHONY: all clean fclean re run valgrind
