/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 12:36:59 by pandalaf         ###   ########.fr       */
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
			std::string			interpret, date;
			double				value;

			databaseBufferStream >> interpret;
			if (interpret == "date,exchange_rate")
				continue;

			size_t	commaPos = interpret.find(',');

			date = interpret.substr(0, commaPos);
			value = std::atof(interpret.substr(commaPos + 1, interpret.length()).c_str());

			if (!isDateFormat(date))
			{
				std::cerr << "Error: Database: invalid date" << std::endl;
				return (1);
			}
			if (value < 0 || value > 1000)
			{
				std::cerr << "Error: Database: value out of range." << std::endl;
				return (1);
			}

			std::cout << "Line: " << interpret << std::endl;
			std::cout << "Date: " << date << ", value: " << value << std::endl;
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