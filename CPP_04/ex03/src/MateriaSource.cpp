/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:25:25 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 17:22:15 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

MateriaSource::MateriaSource(void) {
}

MateriaSource::MateriaSource(const MateriaSource &a) {
    *this = a;
}

MateriaSource::MateriaSource(std::string const & type) : _type(type) {
}

MateriaSource::~MateriaSource(void) {
}

MateriaSource MateriaSource::operator=(const MateriaSource &a) {
    if (this != &a) {
        
    }
}

virtual void learnMateria(AMateria*) {
    
}

virtual AMateria* createMateria(std::string const & type) {
    
}
