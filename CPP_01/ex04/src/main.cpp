/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 00:22:03 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 17:10:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

int clone (std::string filename, std::string s1, std::string s2) {

    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: No se puede abrir el archivo." << std::endl;
        return 1;
    }

    std::ofstream new_file((filename + ".replace").c_str());
    if (!new_file.is_open()) {
        std::cerr << "Error: No se puede abrir el archivo de salida para modificación." << std::endl;
        return 1;
    }

    std::string line;
    while (getline(file, line)) {
        size_t found = line.find(s1);
        while (found != std::string::npos) {
            line.erase(found, s1.length());
            line.insert(found, s2);
            found = line.find(s1, found + s2.length());
        }
        new_file << line << std::endl;
    }

    file.close();
    new_file.close();

    return 0;
}

int main(int argc, char **argv) {

    std::string dir = "./";

    if (argc == 4)
        clone(dir + std::string(argv[1]), argv[2], argv[3]);
    else
        std::cout << "Invalid Input. (EXECUTABLE, FILE, WORD TO REPLACE, REPLACEMENT)" << std::endl;
    return 0;
}
