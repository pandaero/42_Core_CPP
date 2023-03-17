/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:10:16 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/17 13:28:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstdlib>

int	main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}

	std::vector<int>	inVector;
	std::list<int>		inList;

	for (int i = 1; i < argc; ++i)
	{
		if (atoi(argv[i]) < 0)
		{
			std::cerr << "Error: only positive integers accepted." << std::endl;
			return (1);
		}
		inVector.push_back(atoi(argv[i]));
		inList.push_back(atoi(argv[i]));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < inVector.size(); ++i)
	{
		std::cout << inVector[i];
		if (i != inVector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	clock_t	refVector = clock();

	mergeSort(inVector.begin(), inVector.end(), inVector.size());

	clock_t	diffVector = clock() - refVector;

	clock_t	refList = clock();

	mergeSort(inList.begin(), inList.end(), inList.size());

	clock_t	diffList = clock() - refList;


	std::cout << "After : ";
	for (size_t i = 0; i < inVector.size(); ++i)
	{
		std::cout << inVector[i];
		if (i != inVector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process range of " << argc - 1 << " elements with std::vector : " << std::setprecision(1) << std::fixed << 1000000 * ((float) diffVector) / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process range of " << argc - 1 << " elements with std::list   : " << std::setprecision(1) << std::fixed << 1000000 * ((float) diffList) / CLOCKS_PER_SEC << " us" << std::endl;
	return (0);
}