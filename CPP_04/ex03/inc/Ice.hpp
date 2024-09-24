/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:03:30 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/24 14:57:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice(void);
        Ice(Ice const & a);
        ~Ice(void);

        Ice &operator=(Ice const & a);

        AMateria* clone() const;
        void use (ICharacter& target);
};

#endif
