/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:21:56 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/24 15:01:05 by aaespino         ###   ########.fr       */
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
        Character(void);
        Character(Character const & a);
        Character(std::string const & type);
        ~Character(void);

        Character &operator=(const Character &a);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void printMaterias(void);
};

#endif
