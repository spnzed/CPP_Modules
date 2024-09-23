/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:03:30 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 13:25:44 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
    private:
        std::string _type;
    public:
        Cure(void);
        Cure(Cure const & a);
        Cure(std::string const & type);
        ~Cure(void);

        Cure &operator=(Cure const & a);
};

#endif
