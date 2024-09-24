/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:06:00 by aaronespino      ###   ########.fr       */
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

        virtual void        makeSound(void) const;
        virtual std::string getType(void) const;
};

#endif
