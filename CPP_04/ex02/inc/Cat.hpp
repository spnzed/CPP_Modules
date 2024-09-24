/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:07:03 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include <string>

class Cat : public Animal {
    private:
        std::string _type;
        Brain       *brain;
    public:
        Cat(void); 
        Cat(const Cat &a);
        ~Cat(void);

        Cat &operator=(const Cat &a);

        void        makeSound(void) const;
        std::string getType(void)const;
};

#endif
