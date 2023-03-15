/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 13:30:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ExchangeData.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>

#include <set>

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		std::cout << "Database reading" << std::endl;

		std::fstream	databaseFile("data.csv");
		std::string		databaseBuffer;

		std::multiset<ExchangeData>	data;

		while (std::getline(databaseFile, databaseBuffer))
		{
			std::stringstream	databaseBufferStream(databaseBuffer);
			std::string			interpret;

			databaseBufferStream >> interpret;
			if (interpret == "date,exchange_rate")
				continue;

			try
			{
				ExchangeData	member(interpret);
				data.insert(member);
			}
			catch (std::exception & exc)
			{
				std::cerr << exc.what() << std::endl;
				return (1);
			}

			std::cout << "Line: " << interpret << std::endl;
			std::cin.ignore();
		}

	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{

	}

	std::cout << "----- ----- ----- -----" << std::endl;

	{

	}

	std::cout << "----- ----- ----- -----" << std::endl;

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}