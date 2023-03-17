/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 18:15:44 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template <class Iter>
void	mergeSort(Iter first, Iter last)
{
	size_t	size = 0;

	if (first == last)
		return;

	Iter	firstcpy = first;
	while (firstcpy++ != last)
		++size;

	if (size > 1)
	{
		Iter mid = first;
		std::advance(mid, size / 2);
		mergeSort(first, mid);
		mergeSort(mid, last);
		std::inplace_merge(first, mid, last);
	}
}

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other):
	_vector(other._vector),
	_list(other._list)
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe &	PmergeMe::operator=(const PmergeMe & other)
{
	if (this != &other)
	{
		new (this) PmergeMe(other);
	}
	return (*this);
}

int	PmergeMe::operator[](size_t i) const
{
	return (_vector[i]);
}

void	PmergeMe::push(int element)
{
	_vector.push_back(element);
	_list.push_back(element);
}

size_t	PmergeMe::size()
{
	return (_vector.size());
}

void	PmergeMe::mergeSortV()
{
	mergeSort(_vector.begin(), _vector.end());
}

void	PmergeMe::mergeSortL()
{
	mergeSort(_list.begin(), _list.end());
}
