/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:22:29 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/24 13:52:10 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE

#include "../inc/IMateriaSource.hpp"
#include "../inc/AMateria.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria *_materia[4];
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const & a);
        ~MateriaSource(void);

        MateriaSource &operator=(const MateriaSource &a);
    
        void learnMateria(AMateria* materia);
        AMateria* createMateria(std::string const & type);
        void printMaterias(void);
};

#endif
