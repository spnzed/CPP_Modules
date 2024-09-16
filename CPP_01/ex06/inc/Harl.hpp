/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:31:14 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/14 17:32:50 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
    public:
        Harl    (void);
        ~Harl   (void);
        void    complain(std::string level);
        int     getLevelIndex(std::string level);
    private:

        static  void (Harl::*_levels[4])(void);

        static std::string  _ComplainCode[4];
        void                _debug(void);
        void                _info(void);
        void                _warning(void);
        void                _error(void);
};
