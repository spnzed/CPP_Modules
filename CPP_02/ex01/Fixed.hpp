/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/08 18:12:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Fixed {
    public:
        Fixed (void);
        Fixed (const Fixed&);
        Fixed &operator=(const Fixed& a);
        Fixed &operator<<(const Fixed& a);
        ~Fixed (void);
        
        Fixed (const int& a);
        Fixed (const float& a);
        
        int getRawBits (void) const;
        void setRawBits (int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int                 _value;
        static const int    _fractional = 8;
};
