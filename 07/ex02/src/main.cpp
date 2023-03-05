/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/05 23:20:41 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.tpp"

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		Array<int>	arr1;
		Array<int>	arr2(5);

		std::cout << "Created empty int array, size " << arr1.size() << std::endl;
		std::cout << "Created initialised int array, size " << arr2.size() << ":";
		for (int i = 0; i < (int) arr2.size(); i++)
			std::cout << " " << arr2[i];
		std::cout << std::endl;
		
		try
		{
			arr2[80];
		}
		catch (std::exception & exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{
		Array<char>	arr1;
		Array<char>	arr2(10);

		std::cout << "Created empty char array, size " << arr1.size() << std::endl;
		std::cout << "Created initialised char array, size " << arr2.size() << ":";
		for (int i = 0; i < (int) arr2.size(); i++)
			std::cout << " " << arr2[i];
		std::cout << std::endl;
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}