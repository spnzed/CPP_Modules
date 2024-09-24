/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:07:42 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include <string>

class Dog : public Animal {
    private:
        std::string _type;
        Brain       *brain;
    public:
        Dog(void); 
        Dog(const Dog &a);
        ~Dog(void);

        Dog &operator=(const Dog &a);

        void        makeSound(void) const;
        std::string getType(void)const;
};

#endif
