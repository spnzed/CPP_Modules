/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:03:30 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 13:24:17 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    private:
        std::string _type;
    public:
        Ice(void);
        Ice(Ice const & a);
        Ice(std::string const & type);
        ~Ice(void);

        Ice &operator=(Ice const & a);
};

#endif
