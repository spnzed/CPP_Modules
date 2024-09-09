/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:04:33 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/01 23:14:22 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
#include <iostream>
using namespace std;

int main (void) {
    string var = "HI THIS IS BRAIN";
    string *stringPTR = &var;
    string &stringREF = var;

    cout << &var << endl;
    cout << stringPTR << endl;
    cout << &stringREF << endl;

    cout << var << endl;
    cout << *stringPTR << endl;
    cout << stringREF << endl;
}