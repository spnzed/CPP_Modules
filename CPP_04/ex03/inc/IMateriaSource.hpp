/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:22:29 by aaespino          #+#    #+#             */
/*   Updated: 2024/09/23 16:55:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE
#define IMATERIASOURCE

class IMateriaSource {
    public:
        virtual IMateriaSource(void);
        virtual IMateriaSource(IMateriaSource const & a);
        virtual IMateriaSource(std::string const & type);
        virtual ~IMateriaSource() {}

        IMateriaSource &operator=(const IMateriaSource &a);

        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
