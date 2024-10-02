/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:23:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/10/02 18:30:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <class T>
class Array {
  private:
    T* _array;
    size_t _size;
  public:
    Array(void);
    Array(unsigned int n);
    Array(const Array& a);
    ~Array(void);

    Array &operator=(const Array &a);
    T&operator[](size_t index);
    T&operator[](size_t index) const;

    size_t  size(void) const;
};

template <class T>
std::ostream &operator<<(std::ostream& os, const Array<T>& obj);

template <class T>
Array<T>::Array(void) : _size(0) {
    _array = NULL; 
}

template <class T>
Array<T>::Array(unsigned int n) : _size(n) {
    _array = new T[n];
}

template <class T>
Array<T>::Array(const Array& a) : _size(a._size) {
    _array = new T[_size];
    for (size_t i = 0; i < _size; i++) {
        _array[i] = a._array[i];
    }
}

template <class T>
Array<T>::~Array(void) {
    delete[] _array;
}

template <class T>
Array<T>& Array<T>::operator=(const Array &a) {
    if (this != &a) {
        delete _array;
        _size = a._size;
        _array = new T[a._size];
        for (size_t i = 0; i < a.size(); i++) {
            _array[i] = a[i];
        }
    }
    return *this;
}

template <class T>
T& Array<T>::operator[](size_t index){
    
    if (index >= Array<T>::size()) {
        throw std::exception();
    } else {
        return _array[index];
    }
}

template <class T>
T& Array<T>::operator[](size_t index) const {
    
    if (index >= Array<T>::size()) {
        throw std::exception();
    } else {
        return _array[index];
    }
}

template <class T>
size_t Array<T>::size(void) const {
    return _size;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Array<T> &a) {

    for (size_t i = 0; i < a.size() ; i++) {
        os << a[i] << " ";
    }
    return os;
}

#endif
