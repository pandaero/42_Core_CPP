/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/08 17:32:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include "../include/easyfind.tpp"

#include <iostream>
#include <vector>

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		std::vector<int>	arr(5);

		for (int i = 0; i < (int) arr.size(); i++)
			arr[i] = i + 1;
		std::cout << "Created int array in vector container, size " << arr.size() << ":";
		for (int i = 0; i < (int) arr.size(); i++)
			std::cout << " " << arr[i];
		std::cout << std::endl;
		
		try
		{
			std::cout << "Looking for 1, found at index: " << easyfind(arr, 1) - arr.begin() << std::endl;
			std::cout << "Looking for 7: ";
			easyfind(arr, 7);
		}
		catch (std::exception & exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}