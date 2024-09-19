/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/19 13:07:05 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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