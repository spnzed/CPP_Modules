# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 22:46:30 by aaronespino       #+#    #+#              #
#    Updated: 2024/06/05 14:22:26 by aaronespino      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			VARIABLES
SRC		= megaphone.cpp								# SRC almacena el nombre del archivo fuente, megaphone.cpp.
OBJ		= $(SRC:*.cpp=*.o)							# OBJ es la variable que contiene el nombre del archivo objeto.
CC		= g++										# CC define el compilador
RM		= rm -f										# RM define el comando para eliminar archivos, usando 'rm -f'.
FLAGS	= -Wall -Wextra -Werror -std=c++98			# CPPFLAGS contiene los flags para el compilador.
NAME	= megaphone									# NAME define el nombre del ejecutable final.

#			RULES
all		:	$(NAME)									# La regla 'all' es la regla por defecto

$(NAME)	:	$(OBJ)									# Para crear el ejecutable (NAME), necesitamos el archivo objeto (OBJ).
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)
# Compilador (CC) Flags (FLAGS) para compilar el archivo objeto (OBJ) en el ejecutable (NAME).

clean:												# Elimina obj
	$(RM) $(OBJ)

fclean:												# Elimina obj y ejecutable
	$(RM) $(NAME)

re: fclean $(NAME)									# Elimina obj y ejecutable, recompila

.PHONY: all clean fclean re
# .PHONY se usa para declarar que las reglas no son archivos reales.
# Esto evita conflictos si existen archivos con los mismos nombres que las reglas.