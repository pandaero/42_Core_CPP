/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/19 00:12:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <utility>
#include <set>

#include <iostream>

template <class Iter>
void	mergeSort(Iter first, Iter last, size_t size)
{
	if (size > 1)
	{
		Iter mid = first;
		std::advance(mid, size / 2);
		mergeSort(first, mid, size / 2);
		mergeSort(mid, last, size - size / 2);
		std::inplace_merge(first, mid, last);
	}
}

void	PmergeMe::mergeInsertSortV(std::vector<int> & vec)
{
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	last;

	first = vec.begin();
	last = vec.end();

	std::vector<std::set<int> >	pairs;
	if (vec.size() % 2 == 0)
	{
		while (first != last)
		{
			for (int i = 0; i < 2; ++i)
			{
				std::set<int>	pair;
				pair.insert(*first++);
				pair.insert(*first);
				pairs.push_back(pair);
			}
			if (first == last)
				break;
		}
	}
	else
	{
		std::vector<int>::iterator lastElement;
		lastElement = vec.end();
		--lastElement;
		while (first != lastElement)
		{
			std::set<int>	pair;
			pair.insert(*first++);
			pair.insert(*first);
			pairs.push_back(pair);
		}
		std::set <int>	oddOneOut;
		oddOneOut.insert(*last);
		pairs.push_back(oddOneOut);
	}
	std::vector<std::set<int> >::iterator	pairsIt;
	pairsIt = pairs.begin();
	std::cout << *((*pairsIt).begin()) << ", " << *((*pairsIt).end()) << std::endl;
	// std::advance(pairsIt, 2);
	// std::cout << (*pairsIt)[0] << ", " << (*pairsIt)[1] << std::endl;

	// if (size > 1)
	// {
	// 	Iter mid = first;
	// 	std::advance(mid, size / 2);
	// 	mergeSort(first, mid);
	// 	mergeSort(mid, last);
	// 	std::inplace_merge(first, mid, last);
	// }
}

template <class Iter>
void	mergeInsertSortL(Iter first, Iter last, size_t size)
{
	// std::vector<std::vector<int> >	pairs;
	// if (size % 2 == 0)
	// {
	// 	while (first != last)
	// 	{
	// 		for (int i = 0; i < 2; ++i)
	// 		{
	// 			std::vector<int>	pairVector;
	// 			pairVector.push_back(*first++);
	// 			pairVector.push_back(*first);
	// 			pairs.push_back(pairVector);
	// 		}
	// 		if (first == last)
	// 			break;
	// 	}
	// }
	// std::vector<std::vector<int> >::iterator	pairsIt = pairs.begin();
	// std::cout << (*pairsIt)[0] << ", " << (*pairsIt)[1] << std::endl;
	// std::advance(pairsIt, 2);
	// std::cout << (*pairsIt)[0] << ", " << (*pairsIt)[1] << std::endl;
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
	mergeSort(_vector.begin(), _vector.end(), _vector.size());
}

void	PmergeMe::mergeInsertSortV()
{
	mergeInsertSortV(_vector);
}

void	PmergeMe::mergeSortL()
{
	mergeSort(_list.begin(), _list.end(), _list.size());
}

void	PmergeMe::mergeInsertSortL()
{
	// mergeInsertSortL(_list.begin(), _list.end(), _list.size());
}
