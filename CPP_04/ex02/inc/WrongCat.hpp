/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:11 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/20 13:21:18 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "../inc/WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal {
    private:
        std::string _type;
    public:
        WrongCat(void); 
        WrongCat(const WrongCat &a);
        ~WrongCat(void);

        WrongCat &operator=(const WrongCat &a);

        void        makeSound(void) const;
        std::string getType(void)const;
};

#endif
