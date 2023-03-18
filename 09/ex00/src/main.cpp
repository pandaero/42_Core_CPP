/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:30:31 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/18 23:25:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>

int	main(int argc, char ** argv)
{

	if (argc == 2)
	{
		std::string		inFileName(argv[1]);
		std::fstream	inFile(inFileName.c_str());

		if (inFile.fail())
		{
			std::cerr << "Error. could not open input file." << std::endl;
			return (EXIT_FAILURE);
		}

		std::string		dataFileName("data.csv");
		std::fstream	dataFile(dataFileName.c_str());

		if (dataFile.fail())
		{
			std::cerr << "Error. could not open database file (data.csv)." << std::endl;
			return (EXIT_FAILURE);
		}

		BitcoinExchange	exchange;
		try
		{
			BitcoinExchange	exchangeTry(dataFileName);
			exchange = exchangeTry;
		}
		catch (std::exception & exc)
		{
			std::cerr << exc.what() << std::endl;
			return (EXIT_FAILURE);
		}

		std::string	buffer;
		while (getline(inFile, buffer))
		{
			if (buffer.find('|') == std::string::npos)
			{
				std::cerr << "Error: invalid input line." << std::endl;
				continue;
			}
			if (buffer == "date | value")
				continue;
			
			std::size_t	pipePos = buffer.find('|');
			std::string	dateStr(buffer.substr(0, pipePos - 1));
			
			if (!validDate(dateStr))
			{
				std::cerr << "Error: invalide date format" << std::endl;
				continue;
			}
			// if (dateStr < exchange.firstDate())
			// {
			// 	std::cerr << "Error. date predates exchange." << std::endl;
			// 	continue;
			// }

			std::string	queryStr(buffer.substr(pipePos + 2, buffer.length()));
			double		query = std::atof(queryStr.c_str());

			if (query == 0.0)
			{
				std::cerr << "Error: invalid input value." << std::endl;
				continue;
			}
			if (query < 0)
			{
				std::cerr << "Error: negative value." << std::endl;
				continue;
			}
			if (query > 1000)
			{
				std::cerr << "Error: value too large." << std::endl;
				continue;
			}

			if (dateStr > exchange.lastDate())
			{
				std::cout << dateStr << " => " << query << " = " << std::fixed << std::setprecision(2) << exchange.find(dateStr) * query << " (Error: date exceeds exchange.)" << std::endl;
				continue;
			}

			std::cout << dateStr << " => " << query << " = " << std::fixed << std::setprecision(2) << exchange.find(dateStr) * query << std::endl;
		}
		inFile.close();
	}
	else
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
