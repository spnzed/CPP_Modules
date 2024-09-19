/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 12:55:37 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include <string>

class Cat : public Animal {
    private:
        std::string _type;
    public:
        Cat(void); 
        Cat(const Cat &a);
        ~Cat(void);

        Cat &operator=(const Cat &a);

        void        makeSound(void) const;
        std::string getType(void)const;
};