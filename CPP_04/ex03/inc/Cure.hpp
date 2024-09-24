/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:03:30 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/24 14:57:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure(void);
        Cure(Cure const & a);
        ~Cure(void);

        Cure &operator=(Cure const & a);

        AMateria* clone() const;
        void use (ICharacter& target);
};

#endif
