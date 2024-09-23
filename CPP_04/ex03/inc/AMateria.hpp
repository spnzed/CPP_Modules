/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:03:30 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 18:29:24 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "../inc/ICharacter.hpp"

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria(void);
        AMateria(const AMateria &a);
        AMateria(std::string const & type);
        virtual ~AMateria(void);
        
        AMateria &operator=(const AMateria &a);

        std::string const & getName() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use (ICharacter& target);
};

#endif
