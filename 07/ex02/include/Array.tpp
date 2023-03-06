/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:27:54 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/06 01:25:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

#include <iostream>

template <typename T>
Array<T>::Array():
	arr(nullptr),
	len(0)
{
	
}

template <typename T>
Array<T>::Array(const Array & other):
	len(other.len)
{
	arr = new T[other.len];

	for (int i = 0; i < (int) other.len; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	if (arr)
		delete [] arr;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array & other)
{
	if (this != &other)
	{
		len = other.len;
		arr = new T[other.len];
		for (int i = 0; i < other.len; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n):
	len(n)
{
	arr = new T[n];
	for (int i = 0; i < (int) n; i++)
		arr[i] = 0;
}

template <typename T>
T &	Array<T>::operator[](size_t index)
{
	if (index >= len || index < 0)
		throw outBoundsException();
	else
		return (arr[index]);
}

template <typename T>
size_t	Array<T>::size() const
{
	return (len);
}

template <typename T>
const char *	Array<T>::outBoundsException::what() const throw()
{
	return ("Attempted to access member out of bounds of array.");
}
