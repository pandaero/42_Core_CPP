/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/05 22:18:24 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

#include <iostream>
#include <string>

template <typename Type>
void	addone(Type & elem)
{
	elem++;
}

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		int	arr[] = {1, 2, 3, 4, 5, 6};

		std::cout << "Before:";
		for (int i = 0; i < (int) sizeof(arr) / 4; i++)
			std::cout << " " << arr[i];
		std::cout << std::endl;
		std::cout << "Add one..." << std::endl;
		iter(arr, (int) sizeof(arr) / 4, addone);
		std::cout << "After:";
		for (int i = 0; i < (int) sizeof(arr) / 4; i++)
			std::cout << " " << arr[i];
		std::cout << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{
		char	charr[] = {'A', 'a', 'B', 'b', 'C', 'c'};

		std::cout << "Before:";
		for (int i = 0; i < (int) sizeof(charr); i++)
			std::cout << " " << charr[i];
		std::cout << std::endl;
		std::cout << "Add one..." << std::endl;
		iter(charr, (int) sizeof(charr), addone);
		std::cout << "After:";
		for (int i = 0; i < (int) sizeof(charr); i++)
			std::cout << " " << charr[i];
		std::cout << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}