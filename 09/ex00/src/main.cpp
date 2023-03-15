/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 23:37:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE
# define DATE 0
#endif

#ifndef	DATA
# define DATA 0
#endif

#include "../include/Date.hpp"
#include "../include/ExchangeData.hpp"
#include "../include/BitcoinExchange.hpp"

#include <iostream>
#include <set>



#include <cstdlib>
#include <unistd.h>

int	main()
{
	std::cout << "----- ----- ----- -----" << std::endl;

	if (DATE)
	{
		Date	day1;

		std::cout << day1.str() << std::endl;
		day1.takeStr("2020-01-23");
		std::cout << day1.str() << std::endl;

		Date	day2("2021-01-23");
		std::cout << day2.str() << std::endl;

		Date	day3 = day2;
		std::cout << day3 << std::endl;
		day3 = day1;
		std::cout << day3 << std::endl;

		std::cout << "True? " << (day3 == day1) << std::endl;
		std::cout << "True? " << (day2 > day1) << std::endl;
		std::cout << "True? " << (day1 < day2) << std::endl;

		Date	before(2010,01,01);
		Date	after(2021,01,01);

		Date test = before;

		std::cout << test << std::endl;
		while (test != after)
			++test;
		std::cout << test << std::endl;
		try
		{
			while (test != before)
				--test;
		}
		catch (std::exception & exc)
		{
			std::cerr << exc.what() << " Date: " << test << std::endl;
		}
		std::cout << test << std::endl;

		try
		{
			Date	dayofdays(3020, 14, 2);
		}
		catch (std::exception & exc)
		{
			std::cout << "Correctly caught exception: " << exc.what() << std::endl;
		}

		try
		{
			Date	dayofdays(2020, 14, 2);
		}
		catch (std::exception & exc)
		{
			std::cout << "Correctly caught exception: " << exc.what() << std::endl;
		}

		try
		{
			Date	dayofdays(2020, 12, 32);
		}
		catch (std::exception & exc)
		{
			std::cout << "Correctly caught exception: " << exc.what() << std::endl;
		}
	}
	
	std::cout << "----- ----- ----- -----" << std::endl;
	
	if (DATA)
	{
		std::multiset<ExchangeData> set;

		Date	exact(2011, 04, 26);
		Date	close(2011, 04, 28);
		Date	pre(2010, 04, 28);

		ExchangeData	element(exact, 42);
		ExchangeData	search(Date(pre), 0);

		set.insert(element);

		if (set.find(search) == set.end())
		{
			if (search.getDate() < set.begin()->getDate())
			{
				std::cout << "Date before first entry" << std::endl;
			}
			while (set.find(search) == set.end())
			{
				if (set.find(search) != set.end())
				{
					std::cout << "Closest Data found. Value: " << set.find(search)->getValue() << std::endl;
					break;
				}
				sleep(1);
				std::cout << "Before: " << search.getDate() << std::endl;
				Date	tochange = search.getDate();
				--tochange;
				ExchangeData	newSearch(Date(tochange), 0);
				search = newSearch;
				std::cout << "Trying: " << search.getDate() << std::endl;
				if (search.getDate() != set.begin()->getDate())
					std::cout << "Closest Data found. Value: " << set.find(search)->getValue() << std::endl;
			}
			std::cout << "Data not found in set." << std::endl;
		}
		else
			std::cout << "Found Data inside set! Value: " << set.find(search)->getValue() << std::endl;
	}
	
	std::cout << "----- ----- ----- -----" << std::endl;

	{
		std::string		dataFile("data.csv");
		BitcoinExchange	exchange(dataFile);

		std::cout << "Loaded Database." << std::endl;

		try
		{
			std::cout << exchange.findValue(Date("2010-11-13")) << std::endl;
			std::cout << exchange.findValue(Date("2010-10-25")) << std::endl;
			std::cout << exchange.findValue(Date("2009-01-02")) << std::endl;
		}
		catch (std::exception & exc)
		{
			std::cerr << exc.what() << std::endl;
		}
	}

	std::cout << "----- ----- ----- -----" << std::endl;

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}