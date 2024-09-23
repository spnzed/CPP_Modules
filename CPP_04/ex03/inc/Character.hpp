/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:56 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 18:28:12 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../inc/AMateria.hpp"

class Character : public ICharacter {
    private:
        std::string     _type;
        AMateria*       _materia[4];
    public:
        virtual Character(Character const & a);
        virtual Character(std::string const & type);
        virtual ~Character() {}

        Character &operator=(const Character &a);

        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, Character& target) = 0;
};

#endif
