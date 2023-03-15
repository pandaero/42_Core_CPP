/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:22:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/15 22:21:26 by pandalaf         ###   ########.fr       */
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

#include <iostream>
#include <set>

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
		ExchangeData	search(Date(close), 0);

		set.insert(element);

		if (set.find(search) == set.end())
		{
			while (set.find(search) == set.end())
			{

			}
			std::cout << "Data not found in set." << std::endl;
		}
		else
			std::cout << "Found Data inside set! Value: " << set.find(search)->getValue() << std::endl;
	}
	
	std::cout << "----- ----- ----- -----" << std::endl;

	// {
	// 	std::cout << "Database reading" << std::endl;

	// 	std::string		dataFile("data.csv");

	// 	BitcoinExchange	exchange(dataFile);

	// 	try
	// 	{
	// 		std::cout << exchange.getValueAtDate("2010-10-10") << std::endl;
	// 		std::cout << exchange.getValueAtDate("2010-10-25") << std::endl;
	// 		std::cout << exchange.getValueAtDate("2010-08-01") << std::endl;
	// 	}
	// 	catch (std::exception & exc)
	// 	{
	// 		std::cerr << exc.what() << std::endl;
	// 	}
		
	// 	// std::cout << exchange.getValueAtDate("2010-08-29") << std::endl;
		
	// 	// std::cout << exchange.getValueAtDate("2010-09-15") << std::endl;

	// 	// std::multiset<ExchangeData>::iterator	it;
	// 	// it = data.begin();
	// 	// for (int i = 0; i < 10; ++i)
	// 	// {
	// 	// 	std::cout << it->getDate() << " : " << it->getValue() << std::endl;
	// 	// 	it++;
	// 	// }
	// }

	std::cout << "----- ----- ----- -----" << std::endl;

	std::cout << "----- ----- ----- -----" << std::endl;

	return (0);
}