/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:31:14 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 14:16:41 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
    public:
        Harl    (void);
        ~Harl   (void);
        void    complain(std::string level);
    private:
        using level = void (Harl::*)(void);
        
        level           _levels[4];
        std::string     _ComplainCode[4];

        void            _debug(void);
        void            _info(void);
        void            _warning(void);
        void            _error(void);
};
