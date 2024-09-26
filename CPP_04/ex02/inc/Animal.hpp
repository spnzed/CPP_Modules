/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/26 15:22:35 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

#pragma once

class Animal {
    private:
        std::string _type;
    public:
        Animal(void);
        Animal(const Animal &a);
        virtual ~Animal(void);

        Animal &operator=(const Animal &a);

        virtual void        makeSound(void) const = 0; // Abstract Class
        virtual std::string getType(void) const;
};

#endif
