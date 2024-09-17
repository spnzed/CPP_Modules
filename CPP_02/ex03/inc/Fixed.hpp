/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:04:22 by aaronespino       #+#    #+#             */
/*   Updated: 2024/09/17 17:27:06 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Fixed {

    public:

        Fixed (void);
        Fixed (const Fixed&);
        ~Fixed (void);
        Fixed (const int& a);
        Fixed (const float& a);

        Fixed operator+(const Fixed& copy) const;
        Fixed operator-(const Fixed& copy) const;
        Fixed operator*(const Fixed& copy) const;
        Fixed operator/(const Fixed& copy) const;
        Fixed &operator=(const Fixed& a);
        
        int operator>(const Fixed& a);
        int operator<(const Fixed& a);
        int operator>=(const Fixed& a);
        int operator<=(const Fixed& a);
        int operator==(const Fixed& a);
        int operator!=(const Fixed& a);

        Fixed &operator++(void);    //pre
        Fixed &operator--(void);    //pre
        Fixed operator++(int);      //post
        Fixed operator--(int);      //post

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits (void) const;
        void setRawBits (int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int                 _value;
        static const int    _fractional = 8;
};

std::ostream &operator<<(std::ostream& os, const Fixed& obj);
