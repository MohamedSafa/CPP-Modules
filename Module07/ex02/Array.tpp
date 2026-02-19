/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafa <msafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:49:16 by msafa             #+#    #+#             */
/*   Updated: 2026/02/15 00:51:47 by msafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

template <typename T>
Array<T>::Array()
 :array(NULL), n(0)
{}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template <typename T>
Array<T>::Array(unsigned int n)
    :n(n)
{
    array = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& src)
 :array(new T[src.n]()) , n(src.n)
{
    for(unsigned int i = 0; i < n; i++)
        this->array[i] = src.array[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
    if(this != &rhs)
    {
        delete[] this->array;
        this->n = rhs.n;
        this->array = new T[n]();
        for(unsigned int i = 0; i < n;i++)
            this->array[i] = rhs.array[i];
    }
    return *this;
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if(idx >= n)
        throw std::out_of_range("index is out bonds");
    return this->array[idx];
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if(idx >= n)
        throw std::out_of_range("index is out bonds");
    return this->array[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->n;
}