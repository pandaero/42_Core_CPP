/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:20:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 13:27:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void	mergeSort(typename std::vector<int>::iterator first, typename std::vector<int>::iterator last, size_t size = 0)
{
	if (size == 0 && first != last)
		size = std::distance(first, last);
	if (size <= 1)
		return;

	size_t	firstHalf = size / 2;
	size_t	secondHalf = size - firstHalf;
	
	typename std::vector<int>::iterator mid = first;
	std::advance(mid, size / 2);

	mergeSort(first, mid, firstHalf);
	mergeSort(mid,   last, secondHalf);

	std::inplace_merge(first, mid, last);
}

void	mergeSort(typename std::list<int>::iterator first, typename std::list<int>::iterator last, size_t size = 0)
{
	if (size == 0 && first != last)
		size = std::distance(first, last);
	if (size <= 1)
		return;

	size_t	firstHalf = size / 2;
	size_t	secondHalf = size - firstHalf;
	
	typename std::list<int>::iterator mid = first;
	std::advance(mid, size / 2);

	mergeSort(first, mid, firstHalf);
	mergeSort(mid,   last, secondHalf);

	std::inplace_merge(first, mid, last);
}
