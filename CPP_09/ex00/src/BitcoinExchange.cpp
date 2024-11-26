/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:55:23 by aaespino          #+#    #+#             */
/*   Updated: 2024/11/26 17:18:47 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

Bitcoin::Bitcoin(void) {
}

Bitcoin::~Bitcoin(void) {
}

Bitcoin::Bitcoin(const Bitcoin & a) {
    *this = a;
}

Bitcoin& Bitcoin::operator=(const Bitcoin & a) {

    if ( this != &a ) {
        _logs = a._logs;
    }
    return *this;
}

int Bitcoin::isDigits(std::string& str)
{
    for (int i = 0; str[i] ; i++) {
        int v = str[i]; // ASCII Val converted
        if (!(v >= 48 && v <= 57)) {
            return 0;
        }
    }
    return 1;
}

int Bitcoin::countDelimiter(std::string date, char delimiter) {
    
    int count = 0;
    
    for (int i = 0; i < int(date.size()); i++) {
        if (date[i] == delimiter)
            count++;
    }

    return count > 2 ? 1 : 0;
}

// A valid date will always be in the following format: Year-Month-Day
int Bitcoin::compDate(std::string date) {
    char delimiter = '-';  // Delimitador

    std::stringstream ss(date);  // Crear un stringstream a partir de la cadena
    std::string token;
    std::string tokens[3];  // Arreglo de tamaño fijo

    int i = 0;
    // Separar la cadena por el delimitador
    if (countDelimiter(date, delimiter)) {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;        
    }
    while (std::getline(ss, token, delimiter) && i < 3) {
        tokens[i] = trim(token);  // Almacenar cada parte en el arreglo
        i++;
    }
    if (i != 3 || (!isDigits(tokens[0]) || !isDigits(tokens[1]) || !isDigits(tokens[2]))) {
        std::cout << "Error: bad input => " << date << std::endl;
        return 1;
    } else {
        //  años
        if (std::strtol(tokens[0].c_str(), 0, 10) < 2009 ||
            std::strtol(tokens[0].c_str(), 0, 10) > 2022 ) {
            std::cout << "Error: bad input => " << date << std::endl;
            return 1;    
        }
        //  meses
        if (std::strtol(tokens[1].c_str(), 0, 10) < 1 ||
            std::strtol(tokens[1].c_str(), 0, 10) > 12) {
            std::cout << "Error: bad input => " << date << std::endl;
            return 1;
        }
        //  dias
        else {
            // febrero
            if (std::strtol(tokens[1].c_str(), 0, 10) == 2) {
                // años bisiestos
                if (std::strtol(tokens[0].c_str(), 0, 10) == 2012 ||
                    std::strtol(tokens[0].c_str(), 0, 10) == 2016 ||
                    std::strtol(tokens[0].c_str(), 0, 10) == 2020) {
                    if (std::strtol(tokens[2].c_str(), 0, 10) < 1 ||
                        std::strtol(tokens[2].c_str(), 0, 10) > 29) {
                        std::cout << "Error: bad input => " << date << std::endl;
                        return 1;     
                    }
                } else {
                    // años regulares
                    if (std::strtol(tokens[2].c_str(), 0, 10) < 1 ||
                        std::strtol(tokens[2].c_str(), 0, 10) > 28) {
                        std::cout << "Error: bad input => " << date << std::endl;
                        return 1;     
                    }
                }
            }
            // enero a julio
            if (std::strtol(tokens[1].c_str(), 0, 10) > 0 && 
                std::strtol(tokens[1].c_str(), 0, 10) < 8) {
                if (std::strtol(tokens[1].c_str(), 0, 10) % 2 != 0) {
                    if (std::strtol(tokens[2].c_str(), 0, 10) < 1 ||
                        std::strtol(tokens[2].c_str(), 0, 10) > 31) {
                        std::cout << "Error: bad input => " << date << std::endl;
                        return 1;    
                    }
                }
                else {
                    if (std::strtol(tokens[2].c_str(), 0, 10) < 1 ||
                        std::strtol(tokens[2].c_str(), 0, 10) > 30) {
                        std::cout << "Error: bad input => " << date << std::endl;
                        return 1;
                    }
                }   
            }
            // agosto a diciembre
            if (std::strtol(tokens[1].c_str(), 0, 10) > 7 && 
                std::strtol(tokens[1].c_str(), 0, 10) < 13) {
                if (std::strtol(tokens[1].c_str(), 0, 10) % 2 != 0) {
                    if (std::strtol(tokens[2].c_str(), 0, 10) < 1 ||
                        std::strtol(tokens[2].c_str(), 0, 10) > 30) {
                        std::cout << "Error: bad input => " << date << std::endl;
                        return 1;        
                    }
                }
                else {
                    if (std::strtol(tokens[2].c_str(), 0, 10) < 1 ||
                        std::strtol(tokens[2].c_str(), 0, 10) > 31) {
                        std::cout << "Error: bad input => " << date << std::endl;
                        return 1;
                    }
                }   
            }
        }
    }
    return 0;
}

// A valid value must be either a float or a positive integer, between 0 and 1000.
int Bitcoin::compValue(float num) {
    if (num < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }
    if (num > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return 1;
    }
    return 0;
}

std::string Bitcoin::trim(const std::string& str) {
    // Encuentra la posición del primer carácter que no sea espacio
    size_t start = str.find_first_not_of(' ');
    if (start == std::string::npos) {
        return ""; // Si no encuentra ningún carácter no-espacio, la cadena está vacía o solo tiene espacios.
    }

    // Encuentra la posición del último carácter que no sea espacio
    size_t end = str.find_last_not_of(' ');
    
    // Devuelve la subcadena que va desde 'start' hasta 'end'
    return str.substr(start, end - start + 1);
}

float Bitcoin::exchangeRate(std::multimap<std::string, float> *data, const std::string& key, float mul) {
    float ret = 0.0f;

    // Usar lower_bound para encontrar el primer elemento no menor que 'key'
    std::multimap<std::string, float>::const_iterator it = data->lower_bound(key);

    // Si no encontramos una coincidencia exacta
    if (it == data->end() || it->first != key) {
        // Si el iterador apunta al principio, no hay clave anterior, devolvemos 0
        if (it == data->begin()) {
            std::cerr << "Error: no exchange available." << std::endl;
            return 0.0f;
        }
        // Retrocedemos al elemento anterior
        --it;
    }

    // Ahora 'it' es el elemento con la clave exacta o la clave inmediatamente anterior
    ret = it->second * mul;

    return ret;
}

void Bitcoin::makeInput(std::string f) {
    std::ifstream is(f.c_str());

    // std::multimap<std::string, float> ret;

    if (!is) { 
        std::cout << "Error, could not open file." << std::endl; 
        return;
    }

    std::string line;
    std::string row;
    std::string val_s;
    float val;
    
    while(std::getline(is, line)) {
        std::stringstream ss(line);
        std::getline (ss, row , '|');
        std::getline (ss, val_s);

        char *end;
        val = std::strtof(val_s.c_str(), &end);
        this->_logs.insert(std::make_pair(row, val));
    }
    is.close();
}

void Bitcoin::printOutput(std::multimap<std::string, float> *data) {
    for (std::multimap<std::string, float>::iterator it = this->_logs.begin(); it != this->_logs.end(); ++it) {
        if (it->first != "date ") {
            if (compDate(it->first)) {;}
            else if (compValue(it->second)) {;}
            else {
                std::cout << it->first << "=> " << it->second << " = " << exchangeRate(data, it->first, it->second) << std::endl;
            }
        }
    }
}
