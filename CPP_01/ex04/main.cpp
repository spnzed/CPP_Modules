/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 00:22:03 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 02:52:46 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int clone (string filename, string s1, string s2) {

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: No se puede abrir el archivo." << endl;
        return 1;
    }

    ofstream new_file(filename + ".replace");
    if (!new_file.is_open()) {
        cerr << "Error: No se puede abrir el archivo de salida para modificación." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        size_t found = line.find(s1);
        while (found != string::npos) {
            line.erase(found, s1.length());
            line.insert(found, s2);
            found = line.find(s1, found + s2.length());
        }
        new_file << line << endl;
    }

    file.close();
    new_file.close();

    return 0;
}

int main(void) {
    clone("test.txt", "John Doe", "aaespino");
    return 0;
}
