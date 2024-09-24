/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:25:22 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

#pragma once

class WrongAnimal {
    private:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &a);
        virtual ~WrongAnimal(void);

        WrongAnimal &operator=(const WrongAnimal &a);

        void        makeSound(void) const;
        std::string getType(void) const;
};

#endif
