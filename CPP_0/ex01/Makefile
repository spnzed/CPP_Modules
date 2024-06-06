# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 22:46:30 by aaronespino       #+#    #+#              #
#    Updated: 2024/06/05 15:08:17 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES

NAME	= awesome_phonebook					# NAME define el nombre del ejecutable final.

SRC		= Contact.cpp Phonebook.cpp main.cpp		# SRC almacena el nombre del archivo fuente, Contact.cpp Phonebook.cpp.
OBJ		= $(SRC:.cpp=.o)				# OBJ es la variable que contiene el nombre del archivo objeto.
CC		= c++						# CC define el compilador
RM		= rm -f						# RM define el comando para eliminar archivos, usando 'rm -f'.

FLAGS	= -Wall -Wextra -Werror -std=c++98			# CPPFLAGS contiene los flags para el compilador.

#			RULES

all		:	$(NAME)									# La regla 'all' es la regla por defecto

$(NAME)	:	$(OBJ)									# Para crear el ejecutable (NAME), necesitamos el archivo objeto (OBJ).
	$(CC) $(FLAGS) -I ./ -o $(NAME) $(OBJ)

# Compilador (CC) Flags (FLAGS) para compilar el archivo objeto (OBJ) en el ejecutable (NAME).

clean:												# Elimina obj
	$(RM) $(OBJ)

fclean:	clean											# Elimina obj y ejecutable
	$(RM) $(NAME)

re: fclean $(NAME)									# Elimina obj y ejecutable, recompila

.PHONY: all clean fclean re
# .PHONY se usa para declarar que las reglas no son archivos reales.
# Esto evita conflictos si existen archivos con los mismos nombres que las reglas.
