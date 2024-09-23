/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:22:29 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 18:06:01 by aaespino         ###   ########.fr       */
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
        virtual MateriaSource(void);
        virtual MateriaSource(MateriaSource const & a);
        virtual MateriaSource(std::string const & type);
        virtual ~MateriaSource() {}

        MateriaSource &operator=(const MateriaSource &a);
    
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
