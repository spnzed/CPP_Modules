/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:28:07 by aaronespino       #+#    #+#             */
/*   Updated: 2024/06/05 13:50:28 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Para usar std::cout y std::endl
#include <cctype>   // Para usar std::toupper


// std::toupper convierte un caracter a mayúsculas
// std::cout imprime en la consola
// std::endl imprime un salto de línea
int main (int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1 ; i < argc; i++)
        {
            for (int j = 0 ; argv[i][j] != '\0' ; j++)
                std::cout << (char)std::toupper(argv[i][j]);
            if (i + 1 < argc)
                std::cout << " ";
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}